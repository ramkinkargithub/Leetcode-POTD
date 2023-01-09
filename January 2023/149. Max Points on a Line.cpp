/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

Example 1:

Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:

Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4

 

Constraints:

    1 <= points.length <= 300
    points[i].length == 2
    -104 <= xi, yi <= 104
    All the points are unique.
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      if(points.size()==1)
        return 1;
      int ans=2;
      for(int i=0;i<points.size();i++){
        map<double,int>m;
        for(int j=0;j<points.size();j++){
          if(i==j)
            continue;
          int x1 = points[i][0];
          int y1 = points[i][1];
          int x2 = points[j][0];
          int y2 = points[j][1];
          double tangent = atan2((y2-y1),(x2-x1));
          m[tangent]++;

          ans=max(ans,m[tangent]+1);
        }
      }
      return ans;
    }
};
