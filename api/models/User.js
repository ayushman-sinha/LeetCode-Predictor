const mongoose = require("mongoose");

const UserSchema = new mongoose.Schema(
  {
    contest_id: { type: String },
    username: { type: String },
    username_color: { type: String },
    user_badge: { type: String },
    user_slug: { type: String },
    country_code: { type: String },
    country_name: { type: String },
    rank: { type: Number },
    score: { type: Number },
    finish_time: { type: Number },
    global_ranking: { type: Number },
    data_region: { type: String },
  },
  { timestamps: true }
);

module.exports = mongoose.model("User", UserSchema);
