import sys
from PySide2.QtWidgets import QApplication, QMainWindow
from PySide2.QtCore import Qt, Slot, QFile
from .mainwindow_ui import Ui_MainWindow
from ui_frontend.utils.uiffi import UiFfi

class MainWindow_Impl(QMainWindow):
    def __init__(self):
        super(MainWindow_Impl, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.ffi = UiFfi()
        self.connect_slots()

    def connect_slots(self):
        self.ui.pushButton.clicked.connect(self.cb_push_button_clicked)

    @Slot()
    def cb_push_button_clicked(self):
        self.ffi.create_new_project();
        
