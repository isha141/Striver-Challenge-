class trie{
     public:
     trie *links[26];
    trie(){
         for(int i=0;i<26;++i){
             links[i]=nullptr;
         }
    }
};
class node{
    private:
    trie *root;
    public:
    node(){
        root=new trie();
    }
     void insert(string &s,int &ans){
        trie *head=root;
        for(auto itr: s){
             if(head->links[itr-'a']!=NULL){
                 head=head->links[itr-'a'];
             }
             else{
                 ans+=1;   
                 head->links[itr-'a']=new trie();
                 head=head->links[itr-'a'];
             }
        }    
     } 
};
int countDistinctSubstrings(string &s)
{
    node obj;
    int ans=0;
    for(int i=0;i<s.size();++i){
            string temp=s.substr(i);
            obj.insert(temp,ans);
    }
    return ans+1;
}
