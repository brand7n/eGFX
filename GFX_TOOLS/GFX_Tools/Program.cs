using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using LibGFX_Tools;
using JsonExSerializer;

using System.ComponentModel;
using System.Data;
using System.Threading;
using System.Runtime.Serialization.Formatters.Binary; //
using System.Runtime.Serialization;
using System.IO;
using System.IO.Ports;

namespace LibGFX_Tools
{
    class Program
    {

        public static void PostMessages(string output)
        {
            Console.WriteLine(output);
        }


        public static void ShowHelp()
        {
            Console.WriteLine("");
            Console.WriteLine("************************************************************************");
            Console.WriteLine("eGFX_Tools Usage:                                						   ");
            Console.WriteLine("eGFX_Tools  Command  Argument1 Argument2 .....       					   ");
            Console.WriteLine("                                                         			   ");
            Console.WriteLine("Command List:                                            			   ");
            Console.WriteLine("------------------------------------------------------------------------");
            Console.WriteLine("GenerateSprites -- Generates .c and .h files from a folder of .png files");
            Console.WriteLine("                                                                        ");
            Console.WriteLine("Argument1:   Path to folder that has .png images                        ");
            Console.WriteLine("             A .c and .h file will be generated in the directory        ");
            Console.WriteLine("             with the sprites.  the base file names will be the same as ");
            Console.WriteLine("             the search folder.                                         ");
            Console.WriteLine("Argument2:   Target eGFX_ImagePlane Type                                ");
            Console.WriteLine("             Valid types are                                            ");
            Console.WriteLine("             1BPP                                                       ");
            Console.WriteLine("             4BPP.                                                      ");
            Console.WriteLine("             8BPP.                                                      ");
            Console.WriteLine("             all                                                        ");
            Console.WriteLine("                                                          			   ");
            Console.WriteLine("FontBuilder -- Generates .c and .h files from SrcImages  			   ");
            Console.WriteLine("                                                                        ");
            Console.WriteLine("Argument:   Path to folder that has the font data                       ");
            Console.WriteLine("            There should be FontConfiguration.jsx in the folder.        ");
            Console.WriteLine("            If you give it a folder without a .jsx file, an example     ");
            Console.WriteLine("            will be created for you. The Font Folder should have a      ");
            Console.WriteLine("            subfolder with .png images of the font sprites.If none      ");
            Console.WriteLine("            exist, a 5x8 template will be generated. Each ASCII         ");
            Console.WriteLine("            character will have its own .png file  (see examples)       ");
            Console.WriteLine("            Look at an example .jsx for configuration                   ");
            Console.WriteLine("            .h files will have the same base file name as the input     ");
            Console.WriteLine("            folder. The .c and .h files will have the same base         ");
            Console.WriteLine("            file name as the input folder.                              ");
            Console.WriteLine("                                                                        ");
            Console.WriteLine("InitFont  --Generates an Example Template				        	   ");
            Console.WriteLine("                                                                        ");
            Console.WriteLine("Argument1:   Path to folder that the font tempalte                      ");
            Console.WriteLine("Argument2:   Width of the font characters                               ");
            Console.WriteLine("Argument3:   Height of the font characters                              ");
            Console.WriteLine("                                                                         ");
            Console.WriteLine("                                                                        ");
            Console.WriteLine("SliceDice  --Slices and dices an image into smaller pieces       	   ");
            Console.WriteLine("                                                                        ");
            Console.WriteLine("Argument1:   Path to configuration file                                   ");
       
            Console.WriteLine("************************************************************************");
            Console.WriteLine("");
        }
        	
        		 			
        static void Main(string[] args)
        {

            eGFX_Tools MyGFX_Tools = new eGFX_Tools(PostMessages);

             
            try
            {
                if (args.Length == 0)
                {

                    ShowHelp();

                }
                else
                {
                    switch (args[0])
                    {
                        case "r":

                            MyGFX_Tools.Remap(args[1]);
                            break;

                            case "FontBuilder":

                            if (args.Length == 1)
                            {
                                ShowHelp();
                            }
                            else
                            {
                                MyGFX_Tools.FontBuilder(args[1],eGFX_ImagePlaneType.eGFX_IMAGE_PLANE_1BPP);
                            }
                            break;

                        case "InitFont":

                            if (args.Length != 4)
                            {
                                ShowHelp();
                            }
                            else
                            {
                                MyGFX_Tools.InitFont(args[1], Convert.ToInt32(args[2]), Convert.ToInt32(args[3]));
                            }

                            break;

                        case "GenerateSprites":

                            if (args.Length == 1)
                            {
                                ShowHelp();
                            }
                            else
                            {

                                switch(args[2])
                                {
                                    case "1BPP":

                                        MyGFX_Tools.GenerateSprites(args[1], eGFX_ImagePlaneType.eGFX_IMAGE_PLANE_1BPP);

                                        break;
                                    case "4BPP":
                                       
                                        MyGFX_Tools.GenerateSprites(args[1], eGFX_ImagePlaneType.eGFX_IMAGE_PLANE_4BPP);
                                       
                                        break;
                                    case "8BPP":
                                        
                                        MyGFX_Tools.GenerateSprites(args[1], eGFX_ImagePlaneType.eGFX_IMAGE_PLANE_8BPP);
                                        
                                        break;

                                    case "all":
                                        
                                        MyGFX_Tools.GenerateSprites(args[1], eGFX_ImagePlaneType.eGFX_IMAGE_PLANE_1BPP);

                                        MyGFX_Tools.GenerateSprites(args[1], eGFX_ImagePlaneType.eGFX_IMAGE_PLANE_4BPP);

                                        MyGFX_Tools.GenerateSprites(args[1], eGFX_ImagePlaneType.eGFX_IMAGE_PLANE_8BPP);
                                        
                                        break;

                                    default:
                                        PostMessages(args[2] + " is nota  valid plane type");
                                  
                                        break;
                                }

                                
                            } 
                            
                            break;

                        case "SliceDice":

                            if (args.Length == 1)
                            {
                                ShowHelp();
                            }
                            else
                            {
                                MyGFX_Tools.SliceDice(args[1]);
                            } 
                            

                            break;



                        default:

                            ShowHelp();
                            break;
                    }

                }
            }
            catch(Exception Ex)
            {
                Console.WriteLine(Ex.Message);
            }

    
         }
    }
}
