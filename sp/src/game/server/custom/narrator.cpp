#include "cbase.h"
#include "util.h"

class CNarrator : public CLogicalEntity
{
    
    private:
    string_t message;

    public:
    DECLARE_CLASS(CNarrator, CLogicalEntity);

    DECLARE_DATADESC();

    //constructor
    CNarrator()
    {
        
    }

    //input function
    void Display(inputdata_t &inputData);


    //COutputEvent m_OnThreshold; // output event when the counter reaches threshold
};

/* Note: 	There are no semicolons here. 
This is extremely unusual and only occurs 
because the data description is defined using macros! */

LINK_ENTITY_TO_CLASS(tool_narrator, CNarrator);

BEGIN_DATADESC(CNarrator)

    /* DEFINE_FIELD(m_nCounter, FIELD_INTEGER),
    DEFINE_KEYFIELD(m_nThreshold, FIELD_INTEGER, "threshold"),
    DEFINE_INPUTFUNC(FIELD_VOID, "Tick", InputTick),
    DEFINE_OUTPUT(m_OnThreshold, "OnThreshold"), */

END_DATADESC()

/* void CMyLogicalEntity::InputTick(inputdata_t& inputData)
{
    m_nCounter++;

    Msg("Counter value is now %d\n", m_nCounter);

    if (m_nCounter >= m_nThreshold)
    {
        Warning("Threshold reached\n");
        m_OnThreshold.FireOutput(inputData.pActivator, this);

        m_nCounter = 0;
    }
} */

void CNarrator::Display(inputdata_t &inputData)
{
    
}