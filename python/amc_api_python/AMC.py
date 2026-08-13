# Python API for AMC FW 1.5.1
from . import ACS
from .test import Test
from .about import About
from .description import Description
from .network import Network
from .rotcomp import Rotcomp
from .access import Access
from .control import Control
from .diagnostic import Diagnostic
from .move import Move
from .res import Res
from .rtin import Rtin
from .rtout import Rtout
from .update import Update
from .amcids import Amcids
from .status import Status
from .system_service import System_service


class Device(ACS.Device):
    def __init__(self, address):
        super().__init__(address)
        self.pid = "amc"
        self.test = Test(self)
        self.about = About(self)
        self.description = Description(self)
        self.network = Network(self)
        self.rotcomp = Rotcomp(self)
        self.access = Access(self)
        self.control = Control(self)
        self.diagnostic = Diagnostic(self)
        self.move = Move(self)
        self.res = Res(self)
        self.rtin = Rtin(self)
        self.rtout = Rtout(self)
        self.update = Update(self)
        self.amcids = Amcids(self)
        self.status = Status(self)
        self.system_service = System_service(self)
        
        

def discover():
    return Device.discover("amc")
