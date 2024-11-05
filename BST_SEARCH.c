#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};

struct node *tree,*root = NULL;

struct node *createnode(int item) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert(struct node *node, int item) {
    if (node == NULL)
        return createnode(item);
    if (item < node->data) {
        node->left = insert(node->left, item);
    } else if (item > node->data) {
        node->right = insert(node->right, item);
    }
    return node;
}

struct node *search(struct node *root, int x, struct node **parent) {
    struct node *ptr = root;
    *parent = NULL; 
    while (ptr != NULL) {
        if (x < ptr->data) {
            *parent = ptr;
            ptr = ptr->left;
        } else if (x > ptr->data) {
            *parent = ptr; 
            ptr = ptr->right;
        } else {
            return ptr;
        }
    }
    return NULL;
}
void inorder(struct node *root){
	if(root==NULL){
		return;
	}
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right); 
}
void preorder(struct node *root){
	if(root==NULL){
		return;
	}
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
}

int main() {
    int option, item;
    do {
        printf("\n\n****MAIN MENU****");
        printf("\n 1. INSERT");
        printf("\n 2. SEARCH PARENT");
        printf("\n 3. SEARCH CHILD");
        printf("\n 4. INORDER");
        printf("\n 5. PREORDER");
        printf("\n 6. EXIT");
        printf("\n Enter the option:");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter the element:");
                scanf("%d", &item);
                root = insert(root, item);
                break;
            case 2:
                printf("Enter the element to be searched:");
                scanf("%d", &item);
                struct node *parent;
                tree = search(root, item, &parent);
                if (tree) {
                    if (parent) {
                        printf("The parent is: %d\n", parent->data);
                    } else {
                        printf("The element is the root of the tree.\n");
                    }
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 3:
                printf("Enter the element to be searched:");
                scanf("%d", &item);
              	tree = search(root, item, &parent);
                if (tree) {
                    if (tree->left) {
                        printf("The left child is: %d\n", tree->left->data);
                    } else {
                        printf("No left child.\n");
                    }
                    if (tree->right) {
                        printf("The right child is: %d\n", tree->right->data);
                    } else {
                        printf("No right child.\n");
                    }
                } else {
                    printf("Element not found.\n");
                }
                break;
    		case 4:
				printf("Inorder traversal is given by:");
				inorder(root);
				break;
			case 5:
				printf("Preorder traversal is given by:");
				preorder(root);
				break;
				
        }
    } while (option !=6);
    return 0;
}
