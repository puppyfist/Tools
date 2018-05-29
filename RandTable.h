struct Rand_Table
{
    enum	{ max_record_num = 100 };

    unsigned int m_uRecord[max_record_num];
    unsigned int m_uCurPoint;
    unsigned int m_uCount;
    Rand_Table(int nCount) :m_uCount(nCount)
    {
        for(int i = 0; i < m_uCount && i < max_record_num; i++)
            m_uRecord[i] = i;

        Reset();
    }

    void Reset()
    {
        for(int i = 0; i < m_uCount && i < max_record_num; i++)
        {
            unsigned int uFrom = rand() % m_uCount;
            unsigned int uToIndex = rand() % m_uCount;

            unsigned int uBuf = m_uRecord[uToIndex];
            m_uRecord[uToIndex] = m_uRecord[uFrom];
            m_uRecord[uFrom] = uBuf;
        }
        m_uCurPoint = 0;
    }

    unsigned int GetRand()
    {
        if(m_uCurPoint > m_uCount)
            Reset();

        return m_uRecord[m_uCurPoint++];
    }
};