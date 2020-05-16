#include<bits/stdc++.h>

using namespace std;

int dr[4]={-1, 1, 0, 0};
int dc[4]={0, 0, 1, -1};

int main() {
  int r, c, s_i, s_j;
  char ch;
  cin >> r >> c;
  char grid[r][c];
  bool visited[r][c];

  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      cin >> ch;
      grid[i][j]=ch;

      if(ch=='s') {
        s_i=i;
        s_j=j;
      }
         
      visited[i][j]=false;
    }
  }

  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }

  int path=0;
  bool found=false;

  queue<int> x, y, pathCnt;
  x.push(s_i);
  y.push(s_j);
  pathCnt.push(0);

  while(!x.empty()) {
    int _x=x.front();
    int _y=y.front();
    int cnt=pathCnt.front();

    x.pop();
    y.pop();
    pathCnt.pop();

    if(!visited[_x][_y]) {
      visited[_x][_y]=true;
      if(grid[_x][_y]=='e') {
        found=true;
        path=cnt;
        break;
      }
      
      for(int i=0; i<4; i++) {
        int rr=_x+dr[i];
        int cc=_y+dc[i];

        if(rr < 0 || cc < 0) continue;
        if(rr >= r || cc >= c) continue;
        if(visited[rr][cc]) continue;
        if(grid[rr][cc] == '#') continue;

        x.push(rr);
        y.push(cc);
        pathCnt.push(cnt+1);
      }
    } 

  }

  if(found) cout << path << endl;
  else cout << "Not found";

}
