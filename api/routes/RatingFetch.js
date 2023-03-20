const { default: axios } = require("axios");
const router = require("express").Router();
const query = require("./Queries/contestInfo.js");
//const URL = "https://leetcode.com/contest/api/ranking/weekly-contest-121/";
const URL = "https://leetcode.com/contest/api/ranking/biweekly-contest-98/";
const fs = require("fs");
const Bottleneck = require("bottleneck");
const result = require("./RankFetch.js");
const Promises = require("bluebird");
const limiter2 = new Bottleneck({
    maxConcurrent: 1,
    minTime: 800,
    
});

const calc2 = (result) => {
    let res = [];
   const x=Promises.all(result.map(async (item) => {
        
            let username= item.username;
           // if(username[0]=='@') continue;//User maybe DELETED
            let user_region = item.region;        
            
            //console.log(username+ " " + user_region);
            if(user_region === 'CN'){
                const query_url_CN=`https://leetcode-cn.com/graphql?query=query{    
                    userProfilePublicProfile(userSlug: "${username}") {                  
                      profile{
                        contestCount,
                        ranking{
                            currentRating
                          }
                      }
                    }  
                }`
                const response_rating = await limiter2.schedule((response_rating) =>
                  axios.get( query_url_CN)
                );
                
                 if(response_rating.data.data.userProfilePublicProfile==null){
                    item.isFirstContest = false;                
                }
                else{
                    let i=item.rank;
                    item.isFirstContest=response_rating.data.data.userProfilePublicProfile.profile.contestCount===0?true:false,
                    item.rating =response_rating.data.data.userProfilePublicProfile.profile.contestCount===1?1500:parseFloat(response_rating.data.data.userProfilePublicProfile.profile.ranking.currentRating)
                   //console.log(i+" "+username+" "+response_rating.data.data.userProfilePublicProfile.profile.ranking.currentRating)
                    
                }
            }
            else{
                const query_url = `https://leetcode.com/graphql?query=query{userContestRanking(username: "${username}"){rating attendedContestsCount}}`;
                const response_rating = await limiter2.schedule(() =>
                  axios.get(query_url)
                );
                
                if(response_rating.data.data.userContestRanking==null){
                    item.isFirstContest = true;                 
                }
                else{
                    let i=item.rank;
                    item.rating = parseFloat(response_rating.data.data.userContestRanking.rating);
                    //console.log(i+" "+username+" "+response_rating.data.data.userContestRanking.rating);
                }
            }
                
           // res.push(item);
           //console.log(res[res.length-1])
           return item;
    }));
   return x;
}
module.exports = calc2;
