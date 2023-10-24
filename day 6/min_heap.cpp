#include<bits/stdc++.h>
using namespace std;
class minheap{
public:
   int size;
   int cap;
   vector<int>ds;
   minheap(int cap){
     size=0;
     ds.resize(cap,0);
     this->cap=cap;
   }
   void insert(int val){
      if(size+1<cap){ 
       ds.push_back(val);
       size+=1;
       int ind=size-1;
       while(ind>0 && ds[(ind-1)/2]>ds[ind]){
         swap(ds[(ind-1)/2],ds[ind]);
         ind=(ind-1)/2;
       }
      }
      return ;
   } 
   int deleteElement(vector<int>&ds,int ind){
         if(ind>size) 
          return -1;
         int val=ds[ind];
         ds[ind]=ds[size-1];
         int l=2*ind+1;
         int r=2*ind+2;
         int smallest=ind;
         while(true){
         if(l<size && ds[l]<ds[ind]){
           smallest=l; 
         }
         if(r<size && ds[r]<ds[ind]){
           smallest=r; 
         } 
         if(smallest!=ind){
         swap(ds[smallest],ds[ind]);
          ind=smallest;
         }
         else 
           break;
         }
      return val;
   }
};
int main(){
  minheap obj(10);
}
