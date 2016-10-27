#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define null NULL

typedef struct _Node* NPTR;
typedef struct _Node N;


struct _Node {
    int val;
    NPTR left;
    NPTR right;
    
    void N ()
    {
        left = null;
        right = null;
        
    }
};

NPTR insert (NPTR root, int val)
{
    if (root == null)
    {
        root = new N();
        root->val = val;
        return root;
        
    }
    else 
    {
        if (root->val > val)
        {
            if (root->left == null)
            {
                root->left = new N();
                root->left->val = val;                
            }
            else
            {
                insert (root->left, val);
            }
        }
        else
            if (root->val < val)
            {
                if (root->right == null)
                {
                    root->right = new N();
                    root->right->val = val;                
                }
                else
                {
                    insert (root->right, val);
                }
            }

    }
    
    return root;
}


int inorder_traverse (NPTR root)
{
    if (null == root) 0;
    
    int ldepth = 0;
    int rdepth = 0;
    
    if (root->left != null) 
        ldepth = inorder_traverse(root->left);
   
    printf ("%d ",root->val);
    
    if (root->right != null)
       rdepth = inorder_traverse(root->right);
    
    
    if (ldepth > rdepth) 
        return ldepth+1;
    else 
        return rdepth+1;
        
}

int main()
{
    NPTR root = null;
    
    srand (time(NULL));
    
    for (int i=0; i< 1024; i++ ) root = insert (root, rand());
    
    inorder_traverse (root);
    
}