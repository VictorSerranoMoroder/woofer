#pragma once

#include <infra/tables/BaseTableModel.hpp>
#include <infra/elements/Track.hpp>
#include <qobject.h>


namespace infra::tables {


    enum class TableColumns
    {
        Title,
        Author,
        Duration
    };
    
    /// @brief
    ///
    /// @details
    class Track : public BaseTableModel<elements::Track>
    {
        public:
        Track(QObject* parent);
    
        // Copyable
        Track(const Track&) = delete;
        Track& operator=(const Track&) = delete;
    
        // Movable
        Track(Track&&) = delete;
        Track& operator=(Track&&) = delete;

        protected:
        QVariant getColumnData(const elements::Track& track, int column) const override;
        void setColumnData(elements::Track& track, int column, const QVariant& value) override;
        
    };
}