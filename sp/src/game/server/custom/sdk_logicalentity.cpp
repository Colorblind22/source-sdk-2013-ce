#include "cbase.h"
#include "util.h"

class CMyLogicalEntity : public CLogicalEntity
{
    
    private:

    int m_nThreshold; // count that we fire output at
    int m_nCounter; // counter

    public:
    DECLARE_CLASS(CMyLogicalEntity, CLogicalEntity);

    DECLARE_DATADESC();

    //constructor
    CMyLogicalEntity()
    {
        m_nCounter = 0;
    }

    //input function
    void InputTick(inputdata_t &inputData);


    COutputEvent m_OnThreshold; // output event when the counter reaches threshold
};

/* Note: 	There are no semicolons here. 
This is extremely unusual and only occurs 
because the data description is defined using macros! */

LINK_ENTITY_TO_CLASS(my_logical_entity, CMyLogicalEntity);

BEGIN_DATADESC(CMyLogicalEntity)

    DEFINE_FIELD(m_nCounter, FIELD_INTEGER),
    DEFINE_KEYFIELD(m_nThreshold, FIELD_INTEGER, "threshold"),
    DEFINE_INPUTFUNC(FIELD_VOID, "Tick", InputTick),
    DEFINE_OUTPUT(m_OnThreshold, "OnThreshold"),

END_DATADESC()

void CMyLogicalEntity::InputTick(inputdata_t& inputData)
{
    m_nCounter++;

    Msg("Counter value is now %d\n", m_nCounter);

    if (m_nCounter >= m_nThreshold)
    {
        Warning("Threshold reached\n");
        m_OnThreshold.FireOutput(inputData.pActivator, this);

        m_nCounter = 0;
    }
}