import twitter4j.conf.*;
import twitter4j.*;
import twitter4j.auth.*;
import twitter4j.api.*;

import java.util.*;
import processing.serial.*;

Twitter twitter;
String searchString = "#theRealTweetBot";
List<Status> tweets;
long lastTweetId = 0;
long currentTweetId = 1;

String tweet1 = "kipper.move(20) dreher.move(-40)";
String tweet2 = "@bla Hey! kipper.move(20); dreher.move(-40) bitches! #nikosucks";

Serial arduino;

int baudrate = 9600;
int timer = 0;

void setup() {  
  // arduino = new Serial(this, Serial.list()[5], baudrate);

  ConfigurationBuilder cb = new ConfigurationBuilder();
  cb.setOAuthConsumerKey("D7po0bJW6cLY9L4V7OpOrGHav");
  cb.setOAuthConsumerSecret("vWR1xFjR849Z8cahDxmFI3co57Hoztd26abqdQCKQhUxzGuMu0");
  cb.setOAuthAccessToken("2789704130-wUSYL4jTF3I5gLqHD8NKifkJJcEgIbzFeMxo5I2");
  cb.setOAuthAccessTokenSecret("QzEPE1ZKlJipGXh702YWmuez2nweIKosB0wvYIbfAjTdn");

  TwitterFactory twitterFactory = new TwitterFactory(cb.build());
  twitter = twitterFactory.getInstance();

  getNewTweets();
}

void draw() {
  if (millis() - timer >= 6000) {
    timer = millis();
    getNewTweets();

    if (tweets.size() > 0) {
      currentTweetId = tweets.get(0).getId();

      if (currentTweetId != lastTweetId) {
        String[][] movements = processTweet(tweets.get(0).getText());
        if (movements.length > 0) {
          for (int i = 0; i < movements.length; i++) {
            println(movements[i]);
          }
        } else {
          println("I'm afraid I can't do that, Dave.");
        }
        lastTweetId = currentTweetId;
      }
    }
  }
}


String[][] processTweet(String tweet) {
  String[][] content = matchAll(tweet, "([a-z]+)[.]+([a-z]+)[(]+([-]?[0-9]{1,3})[)]");
  return content;
}

void getNewTweets()
{
  try 
  {
    Query query = new Query(searchString);
    QueryResult result = twitter.search(query);
    tweets = result.getTweets();
  } 
  catch (TwitterException te) 
  {
    System.out.println("Failed to search tweets: " + te.getMessage());
    System.exit(-1);
  }
}

