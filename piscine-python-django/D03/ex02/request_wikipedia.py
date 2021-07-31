#!/usr/bin/python3

from json.decoder import JSONDecodeError
import sys
import json
import dewiki
import requests

def search(word: str):
    endpoint = "https://en.wikipedia.org/w/api.php"
    parameters = {
        'action' : 'parse',
        'page' : word,
        'redirects' : True,
        'prop' : 'wikitext',
        'format' : 'json'
    }
    try:
        response = requests.get(url=endpoint, params=parameters)
    except requests.HTTPError as errh:
        raise errh
    try:
        wikidata = response.json()
    except json.JSONDecodeError as errj:
        raise errj
    if wikidata.get("error") != None:
        raise Exception("Error Occurred: ", wikidata.get("error"))
    return (dewiki.from_string(wikidata["parse"]["wikitext"]["*"]))

def run():
    if len(sys.argv) == 2:
        try:
            wiki = search(sys.argv[1])
        except Exception as e:
            return print(e)
        try:
            with open('{}.wiki'.format(sys.argv[1]), 'w') as f:
                f.write(wiki)
        except Exception as e:
            return print(e)
    else:
        print("Error: 2 Arguments required")

if __name__ == '__main__':
    run()