/*A program to solve the N Queen problem (Backtracking Algorithm)*/

import java.util.Scanner;

public class N_QueenProblem
{
    static int count;
    
    public static boolean isSafe(int[][] grid, int i, int j, int n)
    {
        int row;
        int x=i,y=j;
        for(row=0;row<=i-1;row++)
        {
            if(grid[row][j]==1)
                return false;
        }
        while(x>=0 && y>=0)
        {
            if(grid[x][y]==1)
                return false;
            x--;
            y--;
        }
        x=i;
        y=j;
        while(x>=0 && y<n)
        {
            if(grid[x][y]==1)
                return false;
            x--;
            y++;
        }

        return true;
    }

    public static void printGrid(int[][] mat, int n)
    {
        int i,j;
        System.out.println("Correct configuration of queens... ");
        for(i=0;i<=n-1;i++)
        {
            for(j=0;j<=n-1;j++)
            {
                if(mat[i][j]==1)
                    System.out.print("Q ");
                else
                    System.out.print("_ ");
            }
            System.out.println();
        }
    }

    public static boolean NQueenHelper(int[][] grid, int currentRow, int n)
    {
        if(currentRow>=n)
        {
            count++;
            printGrid(grid,n);
            System.out.println();
            return false;
        }
        else
        {
            boolean canNextQueenBePlaced;
            int currentCol=0;
            for(;currentCol<n;currentCol++)
            {
                if(isSafe(grid,currentRow,currentCol,n))
                {
                    grid[currentRow][currentCol]=1;
                    canNextQueenBePlaced=NQueenHelper(grid,currentRow+1,n);
                    if(canNextQueenBePlaced)
                        return true;
                    grid[currentRow][currentCol]=0;
                }
            }
            return false;
        }
    }

    public static void solveNQueen(int[][] grid, int n)
    {
        int currentRow=0;
        NQueenHelper(grid,currentRow,n);
    }

    public static void main(String[] args)
    {
        int n,i,j;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter board size: ");
        n=sc.nextInt();
        int[][] grid=new int[n][n];
        for(i=0;i<=n-1;i++)
            for(j=0;j<=n-1;j++)
                grid[i][j]=0;

        solveNQueen(grid,n);

        System.out.println("\nNumber of configurations: "+count+"\n");

        sc.close();
    }
}