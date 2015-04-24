import java.util.*;
import processing.serial.*;

import twitter4j.conf.*;
import twitter4j.*;
import twitter4j.auth.*;
import twitter4j.api.*;

Serial arduino;
int baudrate = 9600;

Twitter twitter;
String searchString = "#processing";
List<Status> tweets;
long lastTweetId = 0;
long currentTweetId = 1;
int timer = 0;

void setup() {
  arduino = new Serial(this, Serial.list()[5], baudrate);

  ConfigurationBuilder cb = new ConfigurationBuilder();
  cb.setOAuthConsumerKey("D7po0bJW6cLY9L4V7OpOrGHav");
  cb.setOAuthConsumerSecret("vWR1xFjR849Z8cahDxmFI3co57Hoztd26abqdQCKQhUxzGuMu0");
  cb.setOAuthAccessToken("2789704130-wUSYL4jTF3I5gLqHD8NKifkJJcEgIbzFeMxo5I2");
  cb.setOAuthAccessTokenSecret("QzEPE1ZKlJipGXh702YWmuez2nweIKosB0wvYIbfAjTdn");

  TwitterFactory twitterFactory = new TwitterFactory(cb.build());
  twitter = twitterFactory.getInstance();

  //getNewTweets();
}

void draw() {
}

void getNewTweets() {
  try 
  {
    Query query = new Query(searchString);
    QueryResult result = twitter.search(query);
    tweets = result.getTweets();
  } 
  catch (TwitterException te) 
  {
   println("NOT WORKING BITCHES");
  }
}

