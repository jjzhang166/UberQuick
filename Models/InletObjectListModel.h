#ifndef INLETOBJECTLISTMODEL_H
#define INLETOBJECTLISTMODEL_H

#include "QObjectListModelT.h"
#include "../Items/Inlet.h"

namespace Uber {
    class InletObjectListModel : public QObjectListModelT<Inlet*>
    {
        Q_OBJECT
    public:
        InletObjectListModel(QObject *parent = nullptr);
        InletObjectListModel(const QList<Inlet*> &objects, QObject *parent = 0);
        InletObjectListModel(InletObjectListModel *inletListModel, QObject *parent);
        virtual ~InletObjectListModel();
    };
}
#endif // INLETOBJECTLISTMODEL_H
