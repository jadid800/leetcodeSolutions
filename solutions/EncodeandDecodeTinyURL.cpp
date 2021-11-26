/*https://leetcode.com/problems/encode-and-decode-tinyurl/*/
class Solution {
public:
     unordered_map<string, string> longToShort;
    unordered_map<string, string> shortToLong;
    int count=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        // if (longToShort.find(longUrl)!= longToShort.end()){
        //     return longToShort[longUrl];
        // }
        string shortur ="http://tinyurl.com/" +to_string(count);
        count++;
        longToShort[longUrl]=shortur;
        shortToLong[shortur]= longUrl;
        return shortur;
        
    
        
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (shortToLong.find(shortUrl)!= shortToLong.end()){
            return shortToLong[shortUrl];
        }
        return "null";
        
    }
};
