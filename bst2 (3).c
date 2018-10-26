#include<stdio.h>
struct binerytree
{
    int data;
    struct binerytree *left;
    struct binerytree *right;
};
//struct binerytree* root=NULL;
void preorder(struct binerytree*);
struct binerytree* insert(struct binerytree*,int);
void largestnode(struct binerytree*);
void smallestnode(struct binerytree*);
struct binerytree* create(int);
void search(struct binerytree*,int);
int main()
{
    int data,num;
    struct binerytree* root=NULL;
     //struct binerytree* r;
    printf("enter data\n");
    scanf("%d",&data);
    root=insert(root,data);
        printf("enter data\n");
    scanf("%d",&data);
    root=insert(root,data);
            printf("enter data\n");
    scanf("%d",&data);
    root=insert(root,data);
              printf("enter data\n");
    scanf("%d",&data);
    root=insert(root,data);
              printf("enter data\n");
    scanf("%d",&data);
    root=insert(root,data);
              printf("enter data\n");
    scanf("%d",&data);
    root=insert(root,data);
              printf("enter data\n");
    scanf("%d",&data);
    root=insert(root,data);
    preorder(root);
    largestnode(root);
    smallestnode(root);
    printf("enter num\n");
    scanf("%d",&num);
    search(root,num);
    return (0);
}
void preorder(struct binerytree* root)
{
    if(root)
    {
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
struct binerytree* create(int data)
{
   struct binerytree *n;
   n=(struct binerytree*)malloc(sizeof(struct binerytree));
   n->left=NULL;
   n->data=data;
   n->right=NULL;
   return n;
}
    struct binerytree* insert(struct binerytree* root,int data)
{
  struct binerytree *par=root;
       while(par!=NULL)
       {
           if(par->data>data)
           {
               if(par->left==NULL){
                par->left=create(data);
                break;}
                else
           par=par->left;
          }
          else if(par->data<data)
          {
         if(par->data<data)
          {
              if(par->right==NULL){
                par->right=create(data);
              break;}
              par=par->right;
          }
   }
       }
   if(root==NULL)
   return create(data);
   return root;
}
void largestnode(struct binerytree* root)
{

    struct binerytree *par;
    par=root;
    if(root==NULL)
        printf("invalid request\n");
    else
    {
        if(par->right==NULL)
            printf("%d\n",par->data);
        else
        {
            while(par->right!=NULL)
                par=par->right;
            printf("%d\n",par->data);
        }
    }
}
void smallestnode(struct binerytree* root)
{

    struct binerytree *par;
    par=root;
    if(root==NULL)
        printf("invalid request\n");
    else
    {
        if(par->left==NULL)
            printf("%d\n",par->data);
        else
        {
            while(par->left!=NULL)
                par=par->left;
            printf("%d\n",par->data);
        }
    }
}
void search(struct binerytree* root,int num)
{
    int k=0;
    struct binerytree* par;
    par=root;
    if(root==NULL)
    {
        printf("invalid rquest\n");
    }
    else
    {
        if(par->data==num)
        {
            printf("the entered data is present\n");
           // k++;
        }
        else
        {
            if(par->data>num)
                search(par->left,num);
            else
                search(par->right,num);
        }
    }
   // if(k==0)
     //   printf("entered data is not present\n");
}
