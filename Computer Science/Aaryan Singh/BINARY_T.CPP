struct tree{
       int data;
       tree* Right;
       tree* Left;
       };
       
int main(){
   tree* Root = NULL;
   tree* RightBranch = NULL;
   tree* LeftBranch = NULL;
   tree* Current = NULL;
   
    root = new Tree;
    rightBranch = new Tree;
    leftBranch = new Tree;
    current = new Tree;
    
    
   root->data = 1;
    root->Left = LeftBranch;
    root->Right = RightBranch;
    
    rightBranch->data = 3;
    rightBranch->Left = NULL;
    rightBranch->Right = NULL;
    
   leftBranch->data = 2;
    leftBranch->Left = NULL;
    leftBranch->Right = NULL;
    
    current = Root;
    
                  while(current != NULL){
                        cout << current->data << endl;
                        current = current->Left;
                        }
