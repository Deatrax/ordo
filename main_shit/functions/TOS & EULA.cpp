#include <iostream>
using namespace std;

int main(){

    FILE *fp=fopen("EULA-TOS.txt","w");
    fprintf(fp,"End-User License Agreement (EULA)\n\n");

fprintf(fp,"1. Agreement to Terms\n");
fprintf(fp,"By accessing or using the beta version of [Your Project Name] (the \"Software\"), \n");
fprintf(fp,"you (the \"User\") agree to be bound by this End-User License Agreement\n(the \"Agreement\"). ");
fprintf(fp,"If you do not agree to the terms of this Agreement, you may not use the Software.\n\n");

fprintf(fp,"2. Beta Version\n");
fprintf(fp,"This is a closed beta version of the Software, and as such, it is not the \nfinal product. ");
fprintf(fp,"The purpose of this beta release is to allow users to test the Software and\nprovide feedback ");
fprintf(fp,"on its performance, functionality, and potential issues. The Software may\nbe incomplete or ");
fprintf(fp,"contain bugs, and its performance may be unpredictable.\n\n");

fprintf(fp,"3. License Grant\n");
fprintf(fp,"[Your Company Name] grants you a non-exclusive, non-transferable, revocable\nlicense to use ");
fprintf(fp,"the Software solely for the purpose of testing and providing feedback. This\nlicense is ");
fprintf(fp,"granted for personal, non-commercial use only. You may not sublicense or\ntransfer the Software ");
fprintf(fp,"to any third party.\n\n");

fprintf(fp,"4. Feedback\n");
fprintf(fp,"As part of the beta testing process, you may provide feedback, suggestions,\nor recommendations ");
fprintf(fp,"regarding the Software. By submitting feedback, you agree that [Your Company\nName] may use, modify, ");
fprintf(fp,"and incorporate your feedback without any obligation to compensate you.\n\n");

fprintf(fp,"5. Disclaimers\n");
fprintf(fp,"The Software is provided \"AS IS\" without any express or implied warranties.\n");
fprintf(fp,"[Your Company Name] disclaims all warranties, including but not limited to\nwarranties of performance, ");
fprintf(fp,"merchantability, fitness for a particular purpose, and non-infringement. The\nentire risk as to ");
fprintf(fp,"the quality and performance of the Software is with you.\n\n");

fprintf(fp,"6. Limitation of Liability\n");
fprintf(fp,"In no event shall [Your Company Name] be liable for any damages, including but\nnot limited to direct, ");
fprintf(fp,"indirect, incidental, special, consequential, or punitive damages arising out of\nyour use or inability ");
fprintf(fp,"to use the Software, even if [Your Company Name] has been advised of the\npossibility of such damages. ");
fprintf(fp,"This limitation applies to all causes of action, including contract, tort\n(including negligence), ");
fprintf(fp,"strict liability, and breach of warranty.\n\n");

fprintf(fp,"7. Closed Beta\n");
fprintf(fp,"The Software is distributed as part of a closed beta program, meaning\naccess to the Software is restricted ");
fprintf(fp,"and may only be used by users who have been specifically granted permission\nby [Your Company Name]. ");
fprintf(fp,"Unauthorized access or distribution is prohibited.\n\n");

fprintf(fp,"8. Termination\n");
fprintf(fp,"[Your Company Name] reserves the right to terminate this Agreement and your\naccess to the Software ");
fprintf(fp,"at any time, with or without cause. Upon termination, you must immediately\ncease using the Software ");
fprintf(fp,"and destroy all copies of the Software in your possession.\n\n");

fprintf(fp,"9. Governing Law\n");
fprintf(fp,"This Agreement shall be governed by and construed in accordance with the laws\nof [Your Country/State], ");
fprintf(fp,"without regard to its conflict of laws principles.\n\n");


fprintf(fp,"Terms of Service (ToS)\n\n");

fprintf(fp,"1. Acceptance of Terms\n");
fprintf(fp,"By using the beta version of [Your Project Name] (the \"Service\"), you agree\nto be bound by these ");
fprintf(fp,"Terms of Service (the \"Terms\"). If you do not agree to these Terms, you must\nstop using the Service immediately.\n\n");

fprintf(fp,"2. Beta Program\n");
fprintf(fp,"The Service is currently in a closed beta stage. This means that the Service is\nstill under development, ");
fprintf(fp,"and its features, functionality, and performance may not be fully implemented or\nstable. The primary ");
fprintf(fp,"purpose of this beta release is to receive user feedback.\n\n");

fprintf(fp,"3. User Responsibilities\n");
fprintf(fp,"You agree to use the Service only for lawful purposes and in a way that does not\ninfringe on the rights of others. ");
fprintf(fp,"You are responsible for your conduct while using the Service, including ensuring\nthat your use complies ");
fprintf(fp,"with applicable laws and regulations.\n\n");

fprintf(fp,"4. No Warranty\n");
fprintf(fp,"The Service is provided \"AS IS\" without warranties of any kind, either express or\nimplied, including but ");
fprintf(fp,"not limited to implied warranties of merchantability, fitness for a particular\npurpose, or non-infringement. ");
fprintf(fp,"[Your Company Name] does not guarantee that the Service will be error-free,\nuninterrupted, or that any defects ");
fprintf(fp,"will be corrected.\n\n");

fprintf(fp,"5. Limitation of Liability\n");
fprintf(fp,"To the fullest extent permitted by law, [Your Company Name] will not be liable for any\ndamages arising from ");
fprintf(fp,"your use of the Service, including but not limited to direct, indirect, incidental,\nconsequential, or punitive damages. ");
fprintf(fp,"This includes any loss of data, revenue, or profits, and any other commercial damages or losses, even if ");
fprintf(fp,"[Your Company Name] has been advised of the possibility of such damages.\n\n");

fprintf(fp,"6. Data Collection\n");
fprintf(fp,"As part of the beta testing process, [Your Company Name] may collect certain data\nrelated to your use of the Service. ");
fprintf(fp,"This data may include information on bugs, crashes, or general usage patterns. All\ndata collected will be used solely ");
fprintf(fp,"to improve the Service and will be handled in accordance with our Privacy Policy.\n\n");

fprintf(fp,"7. Termination of Access\n");
fprintf(fp,"[Your Company Name] reserves the right to terminate or suspend your access to the\nService at any time, ");
fprintf(fp,"for any reason, without notice or liability.\n\n");

fprintf(fp,"8. Updates\n");
fprintf(fp,"During the beta phase, [Your Company Name] may provide updates to the Service that\nimprove functionality or address issues. ");
fprintf(fp,"You agree to install any such updates to continue using the Service.\n\n");

fprintf(fp,"9. Governing Law\n");
fprintf(fp,"These Terms shall be governed by the laws of [Your Country/State], without regard\nto conflict of laws principles.\n\n");

fprintf(fp,"10. Changes to Terms\n");
fprintf(fp,"[Your Company Name] reserves the right to modify or update these Terms at any time. ");
fprintf(fp,"If changes are made, you will be notified, and your continued use of the Service\nwill constitute acceptance of the new Terms.\n\n");

fclose(fp);
system("start notepad 'EULA-TOS.txt'");
}