with Ada.Command_Line;
with Ada.Text_IO;
with Interfaces.C;
with Ioctl;
procedure Main is
   use all type Interfaces.C.Unsigned;
   function TestIOC return Interfaces.C.Unsigned with
     Import => True,
     Convention => C,
     Link_Name => "testIOC";

   function TestIO return Interfaces.C.Unsigned with
     Import => True,
     Convention => C,
     Link_Name => "testIO";

   function TestIOW return Interfaces.C.Unsigned with
     Import => True,
     Convention => C,
     Link_Name => "testIOW";

   function TestIOR return Interfaces.C.Unsigned with
     Import => True,
     Convention => C,
     Link_Name => "testIOR";

   function TestIOWR return Interfaces.C.Unsigned with
     Import => True,
     Convention => C,
     Link_Name => "testIOWR";

   function TestIOR_BAD return Interfaces.C.Unsigned with
     Import => True,
     Convention => C,
     Link_Name => "testIOR_BAD";

   function TestIOW_BAD return Interfaces.C.Unsigned with
     Import => True,
     Convention => C,
     Link_Name => "testIOW_BAD";


   function TestIO_DIR return Interfaces.C.Unsigned with
     Import => True,
     Convention => C,
     Link_Name => "testIO_DIR";

   function TestIO_TYPE return Interfaces.C.Unsigned with
     Import => True,
     Convention => C,
     Link_Name => "testIO_TYPE";

   function TestIO_SIZE return Interfaces.C.Unsigned with
     Import => True,
     Convention => C,
     Link_Name => "testIO_SIZE";
begin

   if (Ioctl.IOC (16#01#, 16#02#, 16#04#, 16#08#) /= TestIOC) or
     (Ioctl.IO (16#01#, 16#02#) /= TestIO)or
     (Ioctl.IOR (16#01#, 16#02#, 16#04#) /= TestIOR) or
     (Ioctl.IOW (16#01#, 16#02#, 16#04#) /= TestIOW) or
     (Ioctl.IOWR (16#01#, 16#02#, 16#04#) /= TestIOWR) or
     (Ioctl.IO_DIR (16#012345678#) /= TestIO_DIR) or
     (Ioctl.IO_TYPE (16#0123456#) /= TestIO_TYPE) or
     (Ioctl.IO_SIZE (16#0123456#) /= TestIO_SIZE) then

      Ada.Text_IO.Put_Line ("IOC:     "  & Ioctl.IOC (16#01#, 16#02#, 16#04#, 16#08#)'Img & " = " & TestIOC'Img);
      Ada.Text_IO.Put_Line ("IO:      "  & Ioctl.IO (16#01#, 16#02#)'Img &                  " = " & TestIO'Img);
      Ada.Text_IO.Put_Line ("IOR:     "  & Ioctl.IOR (16#01#, 16#02#, 16#04#)'Img &         " = " & TestIOR'Img);
      Ada.Text_IO.Put_Line ("IOW:     "  & Ioctl.IOW (16#01#, 16#02#, 16#04#)'Img &         " = " & TestIOW'Img);
      Ada.Text_IO.Put_Line ("IOWR:    "  & Ioctl.IOWR (16#01#, 16#02#, 16#04#)'Img &        " = " & TestIOWR'Img);
      Ada.Text_IO.Put_Line ("IO_DIR:  "  & Ioctl.IO_DIR (16#012345678#)'Img &               " = " & TestIO_DIR'Img);
      Ada.Text_IO.Put_Line ("IO_TYPE: "  & Ioctl.IO_TYPE (16#0123456#)'Img &                " = " & TestIO_TYPE'Img);
      Ada.Text_IO.Put_Line ("IO_SIZE: "  & Ioctl.IO_SIZE (16#0123456#)'Img &                " = " & TestIO_SIZE'Img);
      Ada.Command_Line.Set_Exit_Status (Ada.Command_Line.Failure);

   end if;

end Main;
