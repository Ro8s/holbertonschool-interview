#!/usr/bin/python3
""" count_it project"""

import requests


def rec(sub, wlist, wdict, wdict_r, after="",):
    """ recfunction """
    url = "https://www.reddit.com/r/{}/hot.json".format(sub)
    url += "?limit=100&after={}".format(after)
    response = requests.get(url,
                            allow_redirects=False,
                            headers={'User-agent': 'Rochos'}
                            )
    if response.status_code != 200:
        return None
    red = response.json().get("data").get("children")
    for article in red:
        titles = article.get("data").get("title").lower().split(" ")
        for title in titles:
            if title in wdict:
                wdict[title] += 1
    after = response.json().get("data").get("after")
    if after is None:
        sorted_w = sorted(wdict.items(), key=lambda t: t[::-1])
        sorted_w_desc = sorted(sorted_w, key=lambda tup: tup[1], reverse=True)
        for w in sorted_w_desc:
            if w[1] > 0:
                print("{}: {}".format(w[0], w[1] * wdict_r[w[0]]))
        return
    return rec(sub, wlist, wdict, wdict_r, after)


def count_words(subreddit, word_list):
    """ countwords prototype """
    wdict = {}
    wdict_r = {}
    word_list = [word.lower() for word in word_list]
    for w in word_list:
        if w not in wdict:
            wdict_r[w] = 1
            wdict[w] = 0
        else:
            wdict_r[w] += 1
    results = rec(subreddit, word_list, wdict, wdict_r)
