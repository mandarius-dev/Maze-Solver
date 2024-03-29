#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED

typedef struct
{
    int x,y;
} coordinates;

extern void push(coordinates *&path,int *dim_path,coordinates stak);
extern void pop(coordinates *&path,int *dim_path);
extern void search_and_move (int i,int j, int *matrix, int n);
extern void dfs_algorithm(int *ma,int d);
extern void clean_matrix (int *ma,int d);

#endif // SOLVER_H_INCLUDED
