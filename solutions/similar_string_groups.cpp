/*https://leetcode.com/problems/similar-string-groups/*/
class disjoint_set {
    vector<int> v;
    int sz;
public:
    disjoint_set(int n) {
        makeset(n);
    }

    void makeset(int n) {
        v.resize(n);
        iota(v.begin(), v.end(), 0);
        sz = n;
    }

    int find(int i) {
        if (i != v[i])
            v[i] = find(v[i]);
        return v[i];
    }
    
    void join(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri != rj) {
            v[ri] = rj;
            sz--;
        }
    }
    
    int size() {
        return sz;
    }
};
class Solution {
    bool isSame(string & s1, string & s2){
        set<char> unmatch;
        int match=0;
        for(int i=0 ; i< s1.size(); i++){
            if(s1[i]!=s2[i]){
                match++;
            }
            if(match==3){return false;}
        }
        return true;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
       
        disjoint_set dset(strs.size());
        for(int i=0 ; i<strs.size(); i++){
            for(int j=i+1; j<strs.size(); j++){
                bool issame = isSame(strs[i],strs[j]);
                if(issame){
                    dset.join(i,j);
                }
            }
        }
        return dset.size();
        
    }
};
