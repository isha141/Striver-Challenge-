Class Solution{
    Public:
   vector<vector<string>>ans;
//  ways of placing a queen in 2-D Matrix; 

bool canPlace(int row,int col,vector<string>&current){
       int column=col;
      int r=row;
     while(column>=0){
      if(current[row][column]==’Q’)
           Return 0;
     Column–;
    } 
column=col;
   while(r<n && column>=0){
    if(current[r][column]==’Q’)
   Return 0;
   r+=1;
Column–;
} 
r=row;
column=col;
while(row>=0 && column>=0){
   if(current[row][column]==’Q’)
    Return 0;
Row–;
Column–;
}
   Return 1;
}
Void ways(int col,vector<string>& current,int n){
     if(col>=n){
     ans.push_back(current);
     Return;
   }  
    for(int i=0;i<n;++i){
      if(canPlace(i,col,curren)){
        current[i][col]=’Q’;
        ways(col+1,current,n);
        current[i][col]=’.’;
      }
  Return ;
}
vector<vector<string>>Nqueens(int n){
       String s(n,’.’);
    vector<string>current;
    for(int i=0;i<n;++i){ 
    current.push_back(s);
   } 
   ways(0,current,n);
   Return ans;
}
};
