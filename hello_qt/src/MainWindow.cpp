#include "MainWindow.hpp"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle("Hello Qt from Codespace");
    resize(400, 200);

    auto* central = new QWidget(this);
    auto* layout = new QVBoxLayout(central);

    m_label = new QLabel("Button not clicked yet", central);
    m_label->setAlignment(Qt::AlignCenter);

    m_button = new QPushButton("Click me", central);

    layout->addWidget(m_label);
    layout->addWidget(m_button);
    setCentralWidget(central);

    connect(m_button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
}

void MainWindow::onButtonClicked()
{
    ++m_clickCount;
    m_label->setText(QString("Clicked %1 times").arg(m_clickCount));
}
