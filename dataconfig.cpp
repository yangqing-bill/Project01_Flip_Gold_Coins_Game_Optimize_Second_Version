#include "dataconfig.h"

DataConfig::DataConfig(QObject *parent)
    : QObject{parent}
{
    int level1Data[4][4] = {{1, 1, 1, 1},
                            {1, 1, 0, 1},
                            {1, 0, 0, 0},
                            {1, 1, 0, 1} } ;

    QVector<QVector<int>> grid;
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {

            row.push_back(level1Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(1,grid);

    int level2Data[4][4] = {{1, 0, 1, 1},
                        {0, 0, 1, 1},
                        {1, 1, 0, 0},
                        {1, 1, 0, 1}} ;

    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level2Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(2,grid);

    int level3Data[4][4] = {{0, 0, 0, 0},
                        {0, 1, 1, 0},
                        {0, 1, 1, 0},
                        {0, 0, 0, 0}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level3Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(3,grid);

    int level4Data[4][4] = {{0, 1, 1, 1},
                        {1, 0, 0, 1},
                        {1, 0, 1, 1},
                        {1, 1, 1, 1}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level4Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(4,grid);

    int level5Data[4][4] = {{1, 0, 0, 1},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {1, 0, 0, 1}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level5Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(5,grid);

    int level6Data[4][4] = {{1, 0, 0, 1},
                        {0, 1, 1, 0},
                        {0, 1, 1, 0},
                        {1, 0, 0, 1}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level6Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(6,grid);

    int level7Data[4][4] = {{0, 1, 1, 1},
                        {1, 0, 1, 1},
                        {1, 1, 0, 1},
                        {1, 1, 1, 0}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level7Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(7,grid);

    int level8Data[4][4] = {{0, 1, 0, 1},
                        {1, 0, 0, 0},
                        {0, 0, 0, 1},
                        {1, 0, 1, 0}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level8Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(8,grid);

    int level9Data[4][4] = {{1, 0, 1, 0},
                        {1, 0, 1, 0},
                        {0, 0, 1, 0},
                        {1, 0, 0, 1}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level9Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(9,grid);

    int level10Data[4][4] = {{1, 0, 1, 1},
                         {1, 1, 0, 0},
                         {0, 0, 1, 1},
                         {1, 1, 0, 1}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level10Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(10,grid);

    int level11Data[4][4] = {{0, 1, 1, 0},
                         {1, 0, 0, 1},
                         {1, 0, 0, 1},
                         {0, 1, 1, 0}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level11Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(11,grid);

    int level12Data[4][4] = {{0, 1, 1, 0},
                         {0, 0, 0, 0},
                         {1, 1, 1, 1},
                         {0, 0, 0, 0}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level12Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(12,grid);

    int level13Data[4][4] = {{0, 1, 1, 0},
                         {0, 0, 0, 0},
                         {0, 0, 0, 0},
                         {0, 1, 1, 0}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level13Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(13,grid);

    int level14Data[4][4] = {{1, 0, 1, 1},
                         {0, 1, 0, 1},
                         {1, 0, 1, 0},
                         {1, 1, 0, 1}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level14Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(14,grid);

    int level15Data[4][4] = {{0, 1, 0, 1},
                         {1, 0, 0, 0},
                         {1, 0, 0, 0},
                         {0, 1, 0, 1}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level15Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(15,grid);

    int level16Data[4][4] = {{0, 1, 1, 0},
                         {1, 1, 1, 1},
                         {1, 1, 1, 1},
                         {0, 1, 1, 0}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level16Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(16,grid);

    int level17Data[4][4] = {{0, 1, 1, 1},
                         {0, 1, 0, 0},
                         {0, 0, 1, 0},
                         {1, 1, 1, 0}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level17Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(17,grid);

    int level18Data[4][4] = {{0, 0, 0, 1},
                         {0, 0, 1, 0},
                         {0, 1, 0, 0},
                         {1, 0, 0, 0}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level18Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(18,grid);

    int level19Data[4][4] = {{0, 1, 0, 0},
                         {0, 1, 1, 0},
                         {0, 0, 1, 1},
                         {0, 0, 0, 0}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level19Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(19,grid);

    int level20Data[4][4] = {{0, 0, 0, 0},
                         {0, 0, 0, 0},
                         {0, 0, 0, 0},
                         {0, 0, 0, 0}} ;
    grid.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int> row;
        for(int j = 0 ; j < 4;j++)
        {
            row.push_back(level20Data[i][j]);
        }
        grid.push_back(row);
    }
    m_dataMap.insert(20,grid);
}
