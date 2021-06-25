#include <stdio.h>
#include <stdlib.h>
# define N 100

int subordinates[N];

// tree data structure
typedef struct      s_tree
{
    int             name;
    struct s_tree   *right;
    struct s_tree   *left;
    
}                   employee;



int                 calculate_subordinates(employee  *node)
{
    // write your code here
    // You are giving a root of a tree, and you goal is to set numnber of 
    // subordinates of each node, and set the value to the array subordinates
    // the array indexing starting from 1.
}

employee            *create_employees_tree(int *arr, int employee_num);

int main()
{
    int n;

    scanf("%d", &n);
    int arr[n + 1];
    for (int i = 2; i <= n; i++)
        scanf("%d", &arr[i]);
    employee *company_tree = create_employees_tree(arr, n);
    
    // calculate_subordinates(company_tree);

    // Printing the solution
    for (int i = 1; i <= n; i++)
        printf("%d ", subordinates[i]);
    
    return 0;
}   

employee            *find_employee(int employee_name, employee *node)
{
    if (node == NULL)
        return NULL;
    if (employee_name == node->name)
        return node;
    employee *left, *right;
    left = find_employee(employee_name, node->left);
    right = find_employee(employee_name, node->right);
    return left ? left : right;
}


// This function take an array indicate each employee
// number with it's boss and construct a tree with this data 
employee            *create_employees_tree(int *arr, int employee_num)
{
    employee *root, *curr, *target;

    root = (employee*)malloc(sizeof(employee));
    root->name = 1;
    root->left = root->right = NULL;
    for (int i = 2; i <= employee_num; i++)
    {
        curr = (employee*)malloc(sizeof(employee));
        curr->name = i;
        root->left = root->right = NULL;
        target = find_employee(i, root);
        if (target->right == NULL)
            target->right = curr;
        else
            target->left = curr;
    }
    return root;
}

void                test_program()
{

}