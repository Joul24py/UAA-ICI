import nltk 
from nltk.stem import WordNetLemmatizer 
nltk.download('wordnet')
nltk.download('averaged_perceptron_tagger') 
nltk.download('punkt')
from nltk.corpus import wordnet 

lemmatizer = WordNetLemmatizer() 
import pandas as pd
datos=pd.read_csv('Team10 Scrapping (Primera Limpieza).csv')
  
def pos_tagger(nltk_tag): 
    if nltk_tag.startswith('J'): 
        return wordnet.ADJ 
    elif nltk_tag.startswith('V'): 
        return wordnet.VERB 
    elif nltk_tag.startswith('N'): 
        return wordnet.NOUN 
    elif nltk_tag.startswith('R'): 
        return wordnet.ADV 
    else:           
        return None
    
archivo="Lemantizacion.csv"
csv=open(archivo,"w")
for a in range(len(datos.iloc[:,7])):
    
    sentence = datos.iloc[a,7]
    
    pos_tagged = nltk.pos_tag(nltk.word_tokenize(sentence))   

    print(pos_tagged) 
  

    wordnet_tagged = list(map(lambda x:(x[0], pos_tagger(x[1])), pos_tagged)) 
    print(wordnet_tagged) 

    lemmatized_sentence = [] 
    
    for word, tag in wordnet_tagged: 
        if tag is None: 
        
            lemmatized_sentence.append(word) 
        else:         
        
            lemmatized_sentence.append(lemmatizer.lemmatize(word, tag)) 
    lemmatized_sentence = " ".join(lemmatized_sentence) 
    lemmatized_sentence = lemmatized_sentence + "\n"
    try:
        csv.write(lemmatized_sentence) 
    except ValueError:
        print("")
    
    