class Solution {
    unordered_map<string, string> longToShort, shortToLong;
    int id = 0;

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (longToShort.find(longUrl) != longToShort.end())
            return longToShort[longUrl];

        string shortUrl = "http://tinyurl.com/" + to_string(id);
        longToShort[longUrl] = shortUrl;
        shortToLong[shortUrl] = longUrl;
        id++;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortToLong[shortUrl];
    }
};
