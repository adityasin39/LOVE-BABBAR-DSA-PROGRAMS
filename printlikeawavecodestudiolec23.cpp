// TC is O(mcols*nRows)
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)

{

    vector<int> ans;

    // Loop to iterate through the columns given to us.

    for (int j = 0; j < mCols; j++)

    {

        // If the current column is even then we will print the elements from top to bottom.

        if (j % 2 == 0)

        {

            for (int i = 0; i < nRows; i++)

            {

                // store the element in the vector.

                ans.push_back(arr[i][j]);

            }

        }

        // Else the elements will be printed from bottom to top.

        else

        {

            for (int i = nRows - 1; i >= 0; i--)

            {

                // store the element in the vector.

                ans.push_back(arr[i][j]);

            }

        }

    }

    return ans;
}