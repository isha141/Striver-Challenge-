#include <bits/stdc++.h> 
class trie{
    public:
    trie *links[26];
    int count; 
    int countpre;
    trie(){
        count=0;
        countpre=0;
        for(int i=0;i<26;++i){
            links[i]=nullptr;
        }
    }
    void increment(){
        count+=1;
    } 
    void incrementPre(){
        countpre+=1;
    } 
    void decrement(){
        count-=1;
    }
    void decPre(){
        countpre-=1;
    }
}; 
class Trie{
    private :
    trie *root;
    public:
    Trie(){
        root=new trie();
    }
    void insert(string &word){
        trie *head=root;
        for(auto itr: word){
            if(head->links[itr-'a']!=NULL){ 
                head=head->links[itr-'a'];
                head->incrementPre();
            }
            else{
                head->links[itr-'a']=new trie();
                head=head->links[itr-'a'];
                head->incrementPre();
            }
        }
        head->increment();
    }

    int countWordsEqualTo(string &word){
        trie *head=root;
        for(auto itr: word){
           if(head->links[itr-'a']!=NULL){
               head=head->links[itr-'a'];
           }
           else
             return 0;
        }
        return head->count;
        // return 0;
    }

    int countWordsStartingWith(string &word){
        trie *head=root;
        for(auto itr: word){
             if(head->links[itr-'a']!=NULL){
                 head=head->links[itr-'a'];
             }
             else
             return 0;
        }
        return head->countpre;
    }

    void erase(string &word){
       trie *head=root;
        for(auto itr: word){
             if(head->links[itr-'a']!=NULL){
                 head=head->links[itr-'a'];
                 head->decPre();
             }
             else
             return ;
        }
        head->decrement();
        return ;
    }
};
