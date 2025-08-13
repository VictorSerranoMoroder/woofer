#include <infra/tables/Track.hpp>

namespace infra::tables 
{
    Track::Track(QObject* parent)
    : BaseTableModel<elements::Track>(parent)
    {

    }

    QVariant Track::getColumnData(const elements::Track& track, int column) const
    {

    }

    void Track::setColumnData(elements::Track& track, int column, const QVariant& value)
    {

    }

}