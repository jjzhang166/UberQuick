#ifndef BLOCKINLET_H
#define BLOCKINLET_H
#include "Inlet.h"
#include "_2RealApplication.h"
#include "StringModel.h"
#include <QDebug>
using namespace _2Real::app;

namespace Uber {
class BlockInlet : public Inlet
{
    Q_OBJECT
public:
    BlockInlet(QObject *parent = 0);
    BlockInlet(const BlockInlet &other);
    BlockInlet( const InletHandle &handle, QObject *parent = 0 );
    virtual ~BlockInlet();

    void                            setInletHandle(const InletHandle& handle );
    InletHandle                     getInletHandle() const;
    virtual inline bool             isValid() const
    {
        return m_InletHandle.isValid();
    }
    StringModel*                  getDataType();
    StringModel*                  getDataTypeFields();

private:
    InletHandle                     m_InletHandle;
    StringModel*                    m_ConnectionOptions;
    StringModel*                    m_DataType;
public slots:
    void setValue(QVariant val)
    {

    }
};
typedef QSharedPointer<BlockInlet>  BlockInletRef;
Q_DECLARE_METATYPE(BlockInlet)
}
#endif // BLOCKINLET_H
