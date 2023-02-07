const { default: axios } = require("axios");
const router=require("express").Router();
const query=require('./Queries/contestInfo.js')
const URL="https://leetcode.com/contest/api/ranking/weekly-contest-291/"
try{
    router.get('/',async(req,res)=>{
        const response = await axios.get(URL);  
        const num_of_users=response.data.user_num;//Total Number of users taking part in the contest
        const total_pages=Math.ceil(num_of_users/25);//Total number of pages        
        res.send(response.data);
    });
}
catch(err){
    console.log(err);
}
     

module.exports=router;