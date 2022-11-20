



void ReLU2D(vector<vector<double>> &result)
{
  for (int i = 0; i < result.size(); i++)
  {
    for (int j = 0; j < result[0].size(); j++)
    {
      if (result[i][j] < 0)
      {
        result[i][j] = 0;
      }
    }
  }
}