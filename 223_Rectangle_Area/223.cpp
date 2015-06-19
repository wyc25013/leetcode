class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
  		int a = (C-A)*(D-B) + (G-E)*(H-F);
  		if((C <= E && A < G) || (C > E && A >= G))
  			return a;
  		if((D <= F && B < H) || (D > F && B >= H))
  			return a;
  		int w[4] = {A,C,E,G};   
  		int h[4] = {B,D,F,H};   
  		vector<int> width(w,w+4);
  		vector<int> height(h,h+4);
  		sort(width.begin(),width.end());
  		sort(height.begin(),height.end());
  		int b = (width[2]-width[1])*(height[2]-height[1]);
  		return a-b;
    }
};