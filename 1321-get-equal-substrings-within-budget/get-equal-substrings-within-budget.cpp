class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l=0,r=0;
        int sum=0;
        int maxlen=INT_MIN;
        int n=s.length();
        while (r<n){
            sum+=abs(s[r]-t[r]);
            while (sum>maxCost){
                sum-=abs(s[l]-t[l]);
                l++;
}
      if (sum<=maxCost){
        maxlen=max(maxlen,(r-l+1));
      }
      r++;
        }
        if (maxlen==INT_MIN){
            return -1;
        }
        return maxlen;
    }
};