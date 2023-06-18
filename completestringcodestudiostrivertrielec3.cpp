struct Node{
    Node* ref[26];
    bool end;
    Node(){
        for( int i=0; i<26; i++ ) ref[i]=NULL;
        end=false;
    }
};
void get_ans( Node* root, string &res, string path){
     
    if( root->end == false)
    {
         return;
    }
    if( path.size() > res.size() ) res=path;
   
    // move to the next char
    for( int i=0; i<26; i++ ){
        if( root->ref[i]!=NULL ) {
            path+=('a'+i);
            get_ans( root->ref[i], res, path );
            path.pop_back();
        }
    }
}
string completeString(int n, vector<string> &a){
    // Write your code here.
    
    // create a trie
    Node* root=new Node();
    root->end=true;
    
    // inserting each string into trie
    for( auto str: a ){
        Node* curr=root;
        for( auto c: str ){
            if( curr->ref[c-'a']==NULL ) curr->ref[c-'a'] = new Node();
            curr = curr->ref[c-'a'];
        }
        curr->end=true;
    }
    
    // findind answer
    string res, path;
    get_ans( root, res, path );
    if( res.size()==0 ) res="None";
    return res;
}