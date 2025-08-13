#pragma once

#include <cstdint>
#include <functional>

#include <QAbstractTableModel>
#include <QList>
#include <qabstractitemmodel.h>
#include <qobject.h>

namespace infra 
{
    /// @brief
    ///
    /// @details
    template <class TData>
    class BaseTableModel : public QAbstractTableModel
    {
        public:
        BaseTableModel(QObject* parent)
        : QAbstractTableModel(parent)
        {

        }
    
        // Non Copyable
        BaseTableModel(const BaseTableModel&) = delete;
        BaseTableModel& operator=(const BaseTableModel&) = delete;
    
        // Non Movable
        BaseTableModel(BaseTableModel&&) = delete;
        BaseTableModel& operator=(BaseTableModel&&) = delete;

        int rowCount(const QModelIndex& parent = QModelIndex()) const override
        {
            return data_model_.size();
        }

        int columnCount(const QModelIndex& parent = QModelIndex()) const override
        {
            Q_UNUSED(parent);
            return columns_.size();
        }

        QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
        {
            if (!index.isValid() || index.row() >= data_model_.size())
                return {};

            if (role == Qt::DisplayRole || role == Qt::EditRole)
            {
                return getColumnData(data_model_[index.row()], index.column());
            }
            return {};
        }

        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
        {
            if (role != Qt::DisplayRole)
                return {};
            if (orientation == Qt::Horizontal && section < columns_.size())
                return columns_[section];
            return {};
        }

        Qt::ItemFlags flags(const QModelIndex& index) const override
        {
            if (!index.isValid())
                return Qt::NoItemFlags;
            return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
        }

        void update_model(std::function<void()> function)
        {
            beginResetModel();
            function();
            endResetModel();
        }

        void append_element(const TData& element)
        {
            int row = data_model_.size();
            beginInsertRows(QModelIndex{}, row, row);
            data_model_.append(element);
            endInsertRows();
        }

        void update_element(std::uint32_t row, const TData& newValue)
        {
            if (row < 0 || row >= data_model_.size()) return;
            data_model_[row] = newValue;
            emit dataChanged(index(row, 0), index(row, columnCount() - 1));
        }

        void remove_element(std::uint32_t row)
        {
            if (row < 0 || row >= data_model_.size()) return;
            beginRemoveRows(QModelIndex{}, row, row);
            data_model_.removeAt(row);
            endRemoveRows();
        }

        protected:
        // Derived classes must implement these for multi-column support
        virtual QVariant getColumnData(const TData& data, int column) const = 0;
        virtual void setColumnData(TData& data, int column, const QVariant& value) = 0;
        
        QList<TData> data_model_;
        QList<QString> columns_; // Column headers
    };
}