#include "Outlet.h"
namespace Uber {
    Outlet::Outlet(QObject *parent)
    :Item(parent)
    {

    }
    Outlet::Outlet(const Outlet &other)
    :Item(other.parent(), other.getPosition(), other.size())
    {

    }
    Outlet::~Outlet()
    {

    }
}
