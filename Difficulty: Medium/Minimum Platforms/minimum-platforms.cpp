class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
           sort(arr.begin(),arr.end());
           sort(dep.begin(),dep.end());
           int l=0,r=0;
           int cnt=0;
           int maxcnt=INT_MIN;
           while (l<arr.size()){
               if (arr[l]<=dep[r]){
                   cnt++;
                   l++;
               }
               else{
                   cnt--;
                   r++;
               }
               maxcnt=max(maxcnt,cnt);
           }
           return maxcnt;
        
    }
    // gzb sol tha ye as sort krne se contadict chije nhi karengi as 
    // agr train arrive nhi hui to vo koi dep me phle thodi aajayegi
    // socho dimag se
    
    // isme mujhe recently kitne platform chaiye uske acc solve kiya h
};
