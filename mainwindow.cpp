#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateView()
{
    ui->spinR2->setValue  ( currentReport.cash.get2Bills()   );
    ui->spinR5->setValue  ( currentReport.cash.get5Bills()   );
    ui->spinR10->setValue ( currentReport.cash.get10Bills()  );
    ui->spinR20->setValue ( currentReport.cash.get20Bills()  );
    ui->spinR50->setValue ( currentReport.cash.get50Bills()  );
    ui->spinR100->setValue( currentReport.cash.get100Bills() );
    ui->spinR001->setValue( currentReport.cash.get1Cents()   );
    ui->spinR005->setValue( currentReport.cash.get5Cents()   );
    ui->spinR010->setValue( currentReport.cash.get10Cents()  );
    ui->spinR025->setValue( currentReport.cash.get25Cents()  );
    ui->spinR050->setValue( currentReport.cash.get50Cents()  );
    ui->spinR1->setValue  ( currentReport.cash.get100Cents() );

    updateTotalBills();
    updateTotalCoins();
    updateTotalCash();

    ui->totalMovimentos->setText       ( QString::number(currentReport.totalCashMovement(), 'f', 2).prepend("R$ ")  );
    ui->caixaPeriodoAnterior->setText  ( QString::number(currentReport.previousPeriodCash(), 'f', 2).prepend("R$ ") );
    ui->vendasDinheiroPeriodo->setText ( QString::number(currentReport.total_sales, 'f', 2).prepend("R$ ")          );
    ui->caixaEsperado->setText         ( QString::number(currentReport.expectedCash(), 'f', 2).prepend("R$ ")       );
    ui->diferencaCaixa->setText        ( QString::number(currentReport.cashDifference(), 'f', 2).prepend("R$ ")     );

    updateCashMovements();

    double cardsTotals[2] = {.0, .0};
    for(std::vector<TotalCardSales>::const_iterator it = currentReport.cards.begin(); it != currentReport.cards.end(); ++it)
    {
        cardsTotals[it->m] += it->total;
        qDebug() << it->fm << ' ' << it->m << ' ' << it->total;
        ui->tableCardsReport->setItem(it->m, it->fm,
                                        new QTableWidgetItem( QString::number(it->total, 'f', 2).prepend("R$ ") )
                                     );
    }
    ui->tableCardsReport->setItem(0, 0, new QTableWidgetItem( QString::number(cardsTotals[0], 'f', 2).prepend("R$ ") ));
    ui->tableCardsReport->setItem(1, 0, new QTableWidgetItem( QString::number(cardsTotals[1], 'f', 2).prepend("R$ ") ));


    ui->txtNotes->setPlainText( currentReport.notes );
}

void MainWindow::addCashMovent()
{
    //ui->tableDepositOrWithdraw;
}

void MainWindow::updateTotalBills()
{
    ui->labelTotalBills->setText( QString::number(currentReport.cash.getTotalBills(), 'f', 2).prepend("R$ ") );
    updateTotalCash();
}

void MainWindow::updateTotalCoins()
{
    ui->labelTotalCoins->setText( QString::number(currentReport.cash.getTotalCoins(), 'f', 2).prepend("R$ ") );
    updateTotalCash();
}

void MainWindow::updateTotalCash()
{
    ui->subtotalCaixa->setText( QString::number(currentReport.cash.getTotal(), 'f', 2).prepend("R$ ") );
}

void MainWindow::updateCashMovements()
{
    ui->tableDepositOrWithdraw->clearContents();

    for(std::vector<CashMovement>::const_iterator it = currentReport.movements.begin(); it != currentReport.movements.end(); ++it)
    {
        ui->tableDepositOrWithdraw->insertRow(ui->tableDepositOrWithdraw->rowCount());

        const int newRow = ui->tableDepositOrWithdraw->rowCount() - 1;
        ui->tableDepositOrWithdraw->setItem(newRow, 0, new QTableWidgetItem( it->when.toString(Qt::TextDate) ));
        ui->tableDepositOrWithdraw->setItem(newRow, 1, new QTableWidgetItem( it->responsible ));
        ui->tableDepositOrWithdraw->setItem(newRow, 2, new QTableWidgetItem( QString::number(it->amount * it->f, 'f', 2).prepend("R$ ") ));
        ui->tableDepositOrWithdraw->setItem(newRow, 3, new QTableWidgetItem( it->description ));
    }
}

void MainWindow::spinR2Changed(int v)
{
    currentReport.cash.set2Bills(v);
    updateTotalBills();
}

void MainWindow::spinR5Changed(int v)
{
    currentReport.cash.set5Bills(v);
    updateTotalBills();
}

void MainWindow::spinR10Changed(int v)
{
    currentReport.cash.set10Bills(v);
    updateTotalBills();
}

void MainWindow::spinR20Changed(int v)
{
    currentReport.cash.set20Bills(v);
    updateTotalBills();
}

void MainWindow::spinR50Changed(int v)
{
    currentReport.cash.set50Bills(v);
    updateTotalBills();
}

void MainWindow::spinR100Changed(int v)
{
    currentReport.cash.set100Bills(v);
    updateTotalBills();
}

void MainWindow::spinR001Changed(int v)
{
    currentReport.cash.set1Cents(v);
    updateTotalCoins();
}

void MainWindow::spinR005Changed(int v)
{
    currentReport.cash.set5Cents(v);
    updateTotalCoins();
}

void MainWindow::spinR010Changed(int v)
{
    currentReport.cash.set10Cents(v);
    updateTotalCoins();
}

void MainWindow::spinR025Changed(int v)
{
    currentReport.cash.set25Cents(v);
    updateTotalCoins();
}

void MainWindow::spinR050Changed(int v)
{
    currentReport.cash.set50Cents(v);
    updateTotalCoins();
}

void MainWindow::spinR1Changed(int v)
{
    currentReport.cash.set100Cents(v);
    updateTotalCoins();
}

void MainWindow::handleAddCashMovent()
{
    currentReport.movements.push_back( CashMovement(QTime::currentTime(), "", .0, CashMovement::Flow::inward, "") );
    ui->tableDepositOrWithdraw->insertRow( ui->tableDepositOrWithdraw->rowCount() );
}

void MainWindow::handleRemoveCashMovent()
{
    qDebug() << ui->tableDepositOrWithdraw->selectedItems().at(0)->row();
    currentReport.movements.erase(currentReport.movements.begin() + ui->tableDepositOrWithdraw->selectedItems().at(0)->row());
    ui->tableDepositOrWithdraw->removeRow( ui->tableDepositOrWithdraw->selectedItems().at(0)->row() );
}

void MainWindow::handleSalesChanged(QString value)
{
//TODO
}

void MainWindow::handleSave()
{
    qDebug() << "save";
}

void MainWindow::handleFinish()
{
    qDebug() << "finish";
}

void MainWindow::handleCardReportChanged(int x,int y)
{
    qDebug() << "item at" << x << ' ' << y;
}

void MainWindow::handleNotesChanged()
{
    currentReport.notes = ui->txtNotes->toPlainText();
}
