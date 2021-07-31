#!/usr/bin/python3

import sys
import requests
from bs4 import BeautifulSoup

def check_word(word, list):
    if word in list:
        return False
    else:
        return True

def search():
    if len(sys.argv) == 2:
        endpoint = "https://en.wikipedia.org/wiki/"
        word = sys.argv[1].replace(" ", "_")
        cnt = 0
        total = []
        
        while word != 'Philosophy':
            total.append(word)
            try:
                response = requests.get(endpoint + word)
            except requests.HTTPError as errh:
                raise errh
            soup = BeautifulSoup(response.text, 'html.parser')
            word = soup.select_one('#mw-content-text > div.mw-parser-output > p > a')
            if word == None:
                return print("It leads to a dead end !")
            elif not check_word(word, total):
                return print("It leads to an infinite loop !")
            else:
                word = word['title']
            cnt += 1
        
        if cnt == 0:
            print("Your input is philosophy !")
        elif word == 'Philosophy':
            for keyword in total:
                print(keyword)
            print(word)
            print('%d roads from %s to philosophy !' % (cnt, total[0]))

    else:
        print("Error: 2 Arguments required")

if __name__ == '__main__':
    search()