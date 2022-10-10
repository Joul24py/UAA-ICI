#%% Uso de librerías
import pandas as pd
import tweepy

#%% Lectura de llaves
stream = open("keys.py")
read_file = stream.read()
exec(read_file)

#%% Conexión con la API
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)
api = tweepy.API(auth)

#%% Definición de valores
num_tweets = 900
created_at = []
description = []
favorite_count = []
full_text = []
identifier = []
in_reply_to_screen_name = []
lang = []
location = []
name = []
screen_name = []
tweet = tweepy.Cursor(api.search, q="nigger", tweet_mode="extended").items(num_tweets)

#%% Extracción de tweets
for i in tweet:
    created_at.append(i.created_at)
    description.append(i.author.description)
    favorite_count.append(i.favorite_count)
    full_text.append(i.full_text)
    identifier.append(i.id)
    lang.append(i.lang)
    location.append(i.author.location)
    in_reply_to_screen_name.append(i.in_reply_to_screen_name)
    name.append(i.author.name)
    screen_name.append(i.author.screen_name)