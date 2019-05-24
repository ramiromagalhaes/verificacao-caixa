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
    delete model;
    delete ui;
}

void MainWindow::updateView()
{
    ui->spinR2->setValue  ( model->cash.get2Bills()   );
    ui->spinR5->setValue  ( model->cash.get5Bills()   );
    ui->spinR10->setValue ( model->cash.get10Bills()  );
    ui->spinR20->setValue ( model->cash.get20Bills()  );
    ui->spinR50->setValue ( model->cash.get50Bills()  );
    ui->spinR100->setValue( model->cash.get100Bills() );
    ui->spinR001->setValue( model->cash.get1Cents()   );
    ui->spinR005->setValue( model->cash.get5Cents()   );
    ui->spinR010->setValue( model->cash.get10Cents()  );
    ui->spinR025->setValue( model->cash.get25Cents()  );
    ui->spinR050->setValue( model->cash.get50Cents()  );
    ui->spinR1->setValue  ( model->cash.get100Cents() );

    updateTotalBills();
    updateTotalCoins();
    updateTotalCash();

    ui->totalMovimentos->setText       ( QString::number(model->totalCashMovement(), 'f', 2).prepend("R$ ")  );
    ui->caixaPeriodoAnterior->setText  ( QString::number(model->previousPeriodCash(), 'f', 2).prepend("R$ ") );
    ui->vendasDinheiroPeriodo->setText ( QString::number(model->total_sales, 'f', 2).prepend("R$ ")          );
    ui->caixaEsperado->setText         ( QString::number(model->expectedCash(), 'f', 2).prepend("R$ ")       );
    ui->diferencaCaixa->setText        ( QString::number(model->cashDifference(), 'f', 2).prepend("R$ ")     );

    updateCashMovements();

    double cardsTotals[2] = {.0, .0};
    for(std::vector<TotalCardSales>::const_iterator it = model->cards.begin(); it != model->cards.end(); ++it)
    {
        cardsTotals[it->m] += it->total;
        ui->tableCardsReport->setItem(it->m, it->fm,
                                        new QTableWidgetItem( QString::number(it->total, 'f', 2).prepend("R$ ") )
                                     );
    }
    ui->tableCardsReport->setItem(0, 0, new QTableWidgetItem( QString::number(cardsTotals[0], 'f', 2).prepend("R$ ") ));
    ui->tableCardsReport->setItem(1, 0, new QTableWidgetItem( QString::number(cardsTotals[1], 'f', 2).prepend("R$ ") ));


    ui->txtNotes->setPlainText( model->notes );
}

void MainWindow::addCashMovent()
{
    //ui->tableDepositOrWithdraw;
}

void MainWindow::updateTotalBills()
{
    ui->labelTotalBills->setText( QString::number(model->cash.getTotalBills(), 'f', 2).prepend("R$ ") );
    updateTotalCash();
}

void MainWindow::updateTotalCoins()
{
    ui->labelTotalCoins->setText( QString::number(model->cash.getTotalCoins(), 'f', 2).prepend("R$ ") );
    updateTotalCash();
}

void MainWindow::updateTotalCash()
{
    ui->subtotalCaixa->setText( QString::number(model->cash.getTotal(), 'f', 2).prepend("R$ ") );
}

void MainWindow::updateCashMovements()
{
    ui->tableDepositOrWithdraw->clearContents();

    for(std::vector<CashMovement>::const_iterator it = model->movements.begin(); it != model->movements.end(); ++it)
    {
        ui->tableDepositOrWithdraw->insertRow(ui->tableDepositOrWithdraw->rowCount());

        const int newRow = ui->tableDepositOrWithdraw->rowCount() - 1;
        ui->tableDepositOrWithdraw->setItem(newRow, 0, new QTableWidgetItem( it->when.toString(Qt::TextDate) ));
        ui->tableDepositOrWithdraw->setItem(newRow, 1, new QTableWidgetItem( it->responsible ));
        ui->tableDepositOrWithdraw->setItem(newRow, 2, new QTableWidgetItem( QString::number(it->amount, 'f', 2).prepend("R$ ") ));
        ui->tableDepositOrWithdraw->setItem(newRow, 3, new QTableWidgetItem( it->description ));
    }
}

void MainWindow::spinR2Changed(int v)
{
    model->cash.set2Bills(v);
    updateTotalBills();
}

void MainWindow::spinR5Changed(int v)
{
    model->cash.set5Bills(v);
    updateTotalBills();
}

void MainWindow::spinR10Changed(int v)
{
    model->cash.set10Bills(v);
    updateTotalBills();
}

void MainWindow::spinR20Changed(int v)
{
    model->cash.set20Bills(v);
    updateTotalBills();
}

void MainWindow::spinR50Changed(int v)
{
    model->cash.set50Bills(v);
    updateTotalBills();
}

void MainWindow::spinR100Changed(int v)
{
    model->cash.set100Bills(v);
    updateTotalBills();
}

void MainWindow::spinR001Changed(int v)
{
    model->cash.set1Cents(v);
    updateTotalCoins();
}

void MainWindow::spinR005Changed(int v)
{
    model->cash.set5Cents(v);
    updateTotalCoins();
}

void MainWindow::spinR010Changed(int v)
{
    model->cash.set10Cents(v);
    updateTotalCoins();
}

void MainWindow::spinR025Changed(int v)
{
    model->cash.set25Cents(v);
    updateTotalCoins();
}

void MainWindow::spinR050Changed(int v)
{
    model->cash.set50Cents(v);
    updateTotalCoins();
}

void MainWindow::spinR1Changed(int v)
{
    model->cash.set100Cents(v);
    updateTotalCoins();
}

void MainWindow::handleAddCashMovent()
{
    model->movements.push_back( CashMovement(QTime::currentTime(), "", .0, CashMovement::Flow::inward, "") );
    ui->tableDepositOrWithdraw->insertRow( ui->tableDepositOrWithdraw->rowCount() );
}

void MainWindow::handleRemoveCashMovent()
{
    qDebug() << ui->tableDepositOrWithdraw->selectedItems().at(0)->row();
    model->movements.erase(model->movements.begin() + ui->tableDepositOrWithdraw->selectedItems().at(0)->row());
    ui->tableDepositOrWithdraw->removeRow( ui->tableDepositOrWithdraw->selectedItems().at(0)->row() );
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
    model->notes = ui->txtNotes->toPlainText();
}
