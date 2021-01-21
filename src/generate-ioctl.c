#include <stdio.h>
#include <sys/ioctl.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
int main(int argc, char *argv[]){

  char *unitname = "ioctl";

  printf("--  -----------------------------------------------------------------\n"
         "--  \n"
         "--  This spec is generated from  the constants and macros found in\n"
         "--  the \"sys/ioctl.h\" file.\n"
         "--  \n"
         "--  -----------------------------------------------------------------\n"
         "with Interfaces.C;\n"
         "with Interfaces.C_Streams;\n"
         "with GNAT.OS_Lib;\n"
         "with System;\n"
         "package %s is\n"
         "   use all type Interfaces.C.Unsigned;\n"
         "   IOC_NRBITS    : constant := %d;\n"
         "   IOC_TYPEBITS  : constant := %d;\n"
         "   IOC_SIZEBITS  : constant := %d;\n"
         "   IOC_DIRBITS   : constant := %d;\n"
         "\n"
         "   IOC_NRMASK    : constant := 16#%X#;\n"
         "   IOC_TYPEMASK  : constant := 16#%X#;\n"
         "   IOC_SIZEMASK  : constant := 16#%X#;\n"
         "   IOC_DIRMASK   : constant := 16#%X#;\n"
         "\n"
         "   IOC_NRSHIFT   : constant := 0;\n"
         "   IOC_TYPESHIFT : constant := (IOC_NRSHIFT + IOC_NRBITS);\n"
         "   IOC_SIZESHIFT : constant := (IOC_TYPESHIFT + IOC_TYPEBITS);\n"
         "   IOC_DIRSHIFT  : constant := (IOC_SIZESHIFT + IOC_SIZEBITS);\n"
         "   IOC_NONE      : constant := %d;\n"
         "   IOC_WRITE     : constant := %d;\n"
         "   IOC_READ      : constant := %d;\n"
         "\n"
         "   function IOC (Dir , Io_Type , Nr, Size_In_Bytes : Interfaces.C.Unsigned) return Interfaces.C.Unsigned is\n"
         "     (Dir * (2 ** IOC_DIRSHIFT) +\n"
         "          Io_Type * (2 ** IOC_TYPESHIFT) +\n"
         "          Nr * (2 ** IOC_NRSHIFT)+\n"
         "          Size_In_Bytes * (2 ** IOC_SIZESHIFT));\n"
         "\n"
         "\n"
         "   --  Used to create numbers.\n"
         "   --\n"
         "   --  NOTE: _IOW means userland is writing and kernel is reading. _IOR\n"
         "   --  means userland is reading and kernel is writing.\n"
         "   --\n"
         "   function IO (Io_Type , Nr : Interfaces.C.Unsigned) return Interfaces.C.Unsigned is\n"
         "     (IOC (IOC_NONE, Io_Type, Nr, 0));\n"
         "\n"
         "   function IOR (Io_Type , Nr, Size_In_Bytes : Interfaces.C.Unsigned) return Interfaces.C.Unsigned is\n"
         "     (IOC (IOC_READ, Io_Type, Nr, Size_In_Bytes));\n"
         "\n"
         "   function IOW (Io_Type , Nr, Size_In_Bytes : Interfaces.C.Unsigned) return Interfaces.C.Unsigned is\n"
         "     (IOC (IOC_WRITE, Io_Type, Nr, Size_In_Bytes));\n"
         "\n"
         "   function IOWR (Io_Type , Nr, Size_In_Bytes : Interfaces.C.Unsigned) return Interfaces.C.Unsigned is\n"
         "     (IOC (IOC_WRITE or IOC_READ , Io_Type, Nr, Size_In_Bytes));\n"
         "\n"
         "   function IOR_BAD (Io_Type , Nr, Size_In_Bytes : Interfaces.C.Unsigned) return Interfaces.C.Unsigned is\n"
         "     (IOC (IOC_READ, Io_Type, Nr, Size_In_Bytes));\n"
         "\n"
         "   function IOW_BAD (Io_Type , Nr, Size_In_Bytes : Interfaces.C.Unsigned) return Interfaces.C.Unsigned is\n"
         "     (IOC (IOC_WRITE, Io_Type, Nr, Size_In_Bytes));\n"
         "\n"
         "\n"
         "   function IO_DIR (Nr : Interfaces.C.Unsigned) return Interfaces.C.Unsigned is\n"
         "     (Nr / (2 ** IOC_DIRSHIFT) and IOC_DIRMASK);\n"
         "\n"
         "   function IO_TYPE (Nr : Interfaces.C.Unsigned) return Interfaces.C.Unsigned is\n"
         "     (Nr / (2 ** IOC_TYPESHIFT) and IOC_TYPEMASK);\n"
         "\n"
         "   function IO_SIZE (Nr : Interfaces.C.Unsigned) return Interfaces.C.Unsigned is\n"
         "     (Nr / (2 ** IOC_SIZESHIFT) and IOC_SIZEMASK);\n"
         "\n"
         "   IOC_IN        : constant := 16#%X#;\n"
         "   IOC_OUT       : constant := 16#%X#;\n"
         "\n"
         "   IOC_INOUT     : constant := 16#%X#;\n"
         "   IOCSIZE_MASK  : constant := 16#%X#;\n"
         "   IOCSIZE_SHIFT : constant := 16#%X#;\n"
         "\n"
         "   --  --------------------------------------------------------------\n"
         "   -- Some simple templates to write own IOCtl functions.\n"
         "   --\n"
         "   function Ioctl (Fd      : GNAT.OS_Lib.File_Descriptor;\n"
         "                   Request : Interfaces.C.Unsigned) return Interfaces.C.Int\n"
         "     with\n"
         "       Convention => C,\n"
         "       Import => True,\n"
         "       Link_Name => \"ioctl\";\n"
         "\n"
         "   function Ioctl (Fd      : GNAT.OS_Lib.File_Descriptor;\n"
         "                   Request : Interfaces.C.Unsigned;\n"
         "                   Data    : System.Address) return Interfaces.C.Int\n"
         "     with\n"
         "       Convention => C,\n"
         "       Import => True,\n"
         "       Link_Name => \"ioctl\";\n"
         "\n"
         "   function Ioctl (Fd      : GNAT.OS_Lib.File_Descriptor;\n"
         "                   Request : Interfaces.C.Unsigned;\n"
         "                   Arg     : Interfaces.C.unsigned_short) return Interfaces.C.Int\n"
         "     with\n"
         "       Convention => C,\n"
         "       Import => True,\n"
         "       Link_Name => \"ioctl\";\n"
         "   --\n"
         "   function Ioctl (Fd      : Interfaces.C_Streams.FILEs;\n"
         "                   Request : Interfaces.C.Unsigned) return Interfaces.C.int\n"
         "     with\n"
         "       Convention => C,\n"
         "       Import => True,\n"
         "       Link_Name => \"ioctl\";\n"
         "\n"
         "   function Ioctl (Fd      : Interfaces.C_Streams.FILEs;\n"
         "                   Request : Interfaces.C.Unsigned;\n"
         "                   Data    : System.Address) return Interfaces.C.int\n"
         "     with\n"
         "       Convention => C,\n"
         "       Import => True,\n"
         "       Link_Name => \"ioctl\";\n"

         "\n"
         "end %s;\n",
         unitname,
         _IOC_NRBITS,
         _IOC_TYPEBITS,
         _IOC_SIZEBITS,
         _IOC_DIRBITS,
         _IOC_NRMASK,
         _IOC_TYPEMASK,
         _IOC_SIZEMASK,
         _IOC_DIRMASK,
         _IOC_NONE,
         _IOC_WRITE,
         _IOC_READ,
         IOC_IN,
         IOC_OUT,
         IOC_INOUT,
         IOCSIZE_MASK,
         IOCSIZE_SHIFT,
         unitname
  );
  return 0;
}
