
/*! \mainpage
 *
 * \section
 *

 
 
 
 
*/





/*! \mainpage
 * 
 * \section intro_sec Introduction
 *
 This document explains the API which allows your custom iOS application to communicate with the new Life Fitness Discover Tablet consoles software and Life Fitness web portal called Life Fitness LFconnect. By embedding this library in your application, you would be able to link with LFconnect and download exerciser workouts and send those to the new Life Fitness equipments. The equipment will communicate with your application via this library to get workouts names, workout parameters and will also send workout results(i.e. speed, distance, time, calories & heart rate) to the library for uploading to LFconnect server for progress tracking. 
 
 As depicted in the digram below, the library provides two main services:
 \n The Device communication service - DeviceCommunicationDelegate 
 \n The Web communication service - WebServiceDelegate
 
 *
 * \section sec_1 Design overview
 *
 *  @image html LFServiceLib_Class.png
 * 
 
 * \section sec_2 How to install the Life Fitness iOS framework to your project 
 * - Click on your application target.  \n
 * - Click on "Build Phases" and expand the "Link With Libraries".  \n
 * - Click on "+" button then go to "Add Other" options.  \n
 * - Navigate to the location of  LFopen.framework and add it.  \n
 
 * \section sec_3 Required iOS SDK Frameworks
 The following iOS frameworks and libraries are required to build with the LFopen API.
 \n
 - <b>  ExternalAccessory.framework </b>
 - <b>  CFNetwork.framework </b>
 - <b>  SystemConfiguration.framework </b>
 - <b>  MobileCoreServices.framework </b>
 - <b>  libz.dylib </b>
 - <b>  libxml2.dylib </b>
 
 Apart from that please add following linker flag for your project. If developer forgets to set the options mentioned below he will get runtime error “unrecognized selector sent to instance”
 - <b> -ObjC </b>
 - <b> -all_load </b>
 
 
 
 * \section sec_4 How to configure Device Communication Protocol
 This section describes the communication protocol between the Life Fitness console software and the iPod/iPhone(iOS) application through the LFopen API. All console-app communications take place within the DevDataTransfer and iPodDataTransfer iAP commands. To facilitate this communication, the library exposes simple interface as shown in the diagram above. Typically the sequence of information exchange happens as follows:
- Life Fitness console sends requests to LFopen API,
- LFopen API expects necessary data from you, the API user and
- LFopen API responds to Life Fitness console with data you provided.
<p> One exception to this flow happens when the Life Fitness console sends workout results back to the LFopen API, the API then sends it back to your application for transmission to the LFconnect website or any other tracking website.</p>

 To be able to initialize communication between iOS device and the Life Fitness console, iPhone application must define the communication protocol string which is used for the Discover Tablet Console. This is done as follows:
- Open Info.plist file and add the following key: <i>UISupportedExternalAccessoryProtocols</i>
- Click on + sign to add a protocol string. You will see Item 0 added as a row below the key defined above
- Add the following protocol string as value to the above key: <i>com.lifefitness.vtapp.protocol</i>   \n

 <b>Note : To work on background mode, add the "external-accessory" values to the UIBackgroundModes key in the application's info.plist.<b>\n
 
 * \section sec_5 How to configure License
 Before using Life Fitness iOS library, the developer must obtain a license to each iOS app from our Life Fitness website. Once you register as a developer and register the iOS app, the website gives a license for the particular app. For details of how to obtain development license, please contact LifeFitness.
 
 In order to use LFopen API, the developer must supply the valid license key generated by Life Fitness before using any of the methods in this API. Calling any methods without supplying a valid license code will result in an Exception. To supply the license given by Life Fitness, simply add new key 'LFLicenseKey', to the application info.plist file and set license string for the value, or just call "-(void) setLicence:(NSString*)strLicence" method to activate LFopen library.
 \code{.cpp}
        LFServiceProvider *serviceProvider = [LFServiceProvider getInstance];
        [serviceProvider registerForDeviceService:self simulation:NO];
        [serviceProvider registerForWebService:self];
        [serviceProvider setLicence:@"testlicense"];
 \endcode
 
 LFopen has two connectivity types, QA and Production. When you build the project with LFopen library choose the appropriate server (QA or Production) according to your objective. In order to accomplish that you have to add 'LFConnectivity' key to the application info.plist file. It can have either 'QA' or 'Production' as value according to developer build requirement. This will only effect if you access LFopen webservice and no impact for the equipment connectivity. You can create QA user to test your project using below URL.
    
    ' https://vtqa.lfconnect.com/web '
 
 *  Here is a sample .plist file
 *  @image html sample_protocl_definition.png
 

 * \section sec_6 Example Usage
 * \subsection subsec_1 1) Device Communication Service
 <p>The 'DeviceCommunicationDelegate' provides a functional interface to the users who use LFopen API to communicate with Life Fitness devices.
 The user who is willing to communicate with the Life Fitness equipment can create 'LFServiceProvider' object and then register for the device service. User has ability to simulate or debug console behavior by changing 'simulation' parameter. Equipment simulation mode will assume that the user has selected the random workout preset from the provided list by user. </p>
  <b>Example:</b>
 \code{.cpp}
 LFServiceProvider *serviceProvider = [LFServiceProvider getInstance];
 [serviceProvider registerForDeviceService:self simulation:NO];
 \endcode
 
<p> Next implement the 'DeviceCommunicationDelegate' protocol in order to listen to the console. Workout summary data is provided every one second through the API. Here we have provided sample implementation of the 'DeviceCommunicationDelegate. It shows how to send and retrieve data from LifeFitness consoles.</p>
  <b>Example:</b>
 \code{.cpp}
 #pragma -
 #pragma devicelib delegate
 
 -(void) didDeviceConnect;
 {
    NSLog(@"didDeviceConnect");
 }
 
 -(void) didDeviceDisconnect
 {
    NSLog(@"didDeviceDisconnect");
 }
 
-(int) numberOfPresetsToShow:(enum LFDeviceType) deviceTypeValue
 {
    if (deviceTypeValue == LFDeviceType_Treadmill_Discover_Engage) {
        NSLog(@"numberOfPresetsToShow == %d",presetList.count );
        return presetList.count;
    }
 }
 
 -(NSMutableArray*)presetListToShowFrom:(NSInteger)fromIndex toIndex:(NSInteger)toIndex
 {
    NSMutableArray *presetsNameList = [[NSMutableArray alloc] init];
 
    for (int i = fromIndex; i < toIndex; i++)
    {
        if (i >= presetList.count) break;
        [presetsNameList addObject:((Workout*)[presetList objectAtIndex:i]).workoutName];
    }
 
    return presetsNameList;
 }
 
 -(NSString*)presetDataForIndex:(NSInteger)index;
 {
    Workout *workoutData = [presetList objectAtIndex:0];
    NSString *file = workoutData.fileData;
    file = [workoutDataList objectForKey:@"file"];
    return file;
 }
 
 -(NSString*)playListNameForIndex:(NSInteger)index
 {
    return @"TredmillMusic.mp3";
 }
 
 -(void)didReceivedResultFileName:(NSString*)fileName
 {
    NSLog(@"RESULT FILE NAME : %@", fileName);
 }
 
 -(void)didReceivedWorkoutStream:(LFWorkoutStream*)streamData
 {
    NSLog(@"RESULT CONSOLE STREAM streamVersion : %d", streamData.streamVersion);
    NSLog(@"RESULT CONSOLE STREAM elapsedWorkoutSeconds : %d", streamData.elapsedWorkoutSeconds);
    NSLog(@"RESULT CONSOLE STREAM targetWorkoutSeconds : %d", streamData.targetWorkoutSeconds);
    NSLog(@"RESULT CONSOLE STREAM accumulatedCalories : %d", streamData.accumulatedCalories);
    NSLog(@"RESULT CONSOLE STREAM targetCalories : %d", streamData.targetCalories);
    NSLog(@"RESULT CONSOLE STREAM accumulatedDistance : %.2f", streamData.accumulatedDistance);
    NSLog(@"RESULT CONSOLE STREAM targetDistance : %.2f", streamData.targetDistance);
    NSLog(@"RESULT CONSOLE STREAM accumulatedDistanceClimbedMeter : %d", streamData.accumulatedDistanceClimbedMeter);
    NSLog(@"RESULT CONSOLE STREAM targetDistanceClimbedMeter : %d", streamData.targetDistanceClimbedMeter);
    NSLog(@"RESULT CONSOLE STREAM currentSpeedRPM : %d", streamData.currentSpeedRPM);
    NSLog(@"RESULT CONSOLE STREAM currentSpeedKM: %f", streamData.currentSpeedKM);
    NSLog(@"RESULT CONSOLE STREAM targetSpeedKM : %f", streamData.targetSpeedKM);
    NSLog(@"RESULT CONSOLE STREAM currentIncline : %f", streamData.currentIncline);
    NSLog(@"RESULT CONSOLE STREAM targetIncline : %f", streamData.targetIncline);
    NSLog(@"RESULT CONSOLE STREAM currentHeartRate : %d", streamData.currentHeartRate);
    NSLog(@"RESULT CONSOLE STREAM targetHeartRate : %d", streamData.targetHeartRate);
    NSLog(@"RESULT CONSOLE STREAM currentResistance : %d", streamData.currentResistance);
    NSLog(@"RESULT CONSOLE STREAM currentLevel : %d", streamData.currentLevel);
    NSLog(@"RESULT CONSOLE STREAM workoutState : %d", streamData.workoutState);
 }
 
 -(void)didReceivedResultData:(NSString*)fileData
 {
    NSLog(@"RESULT FILE DATA : %@", fileData);
    @autoreleasepool 
    {
        LFOAuthAccessToken *token = (LFOAuthAccessToken*)[NSKeyedUnarchiver unarchiveObjectWithFile:@"YourPath/yourFileName"];
        LFWorkoutResultRequest *request = [[LFWorkoutResultRequest alloc] init] autorelease];
        request.access_token = token.accessToken;
        request.resultFile = fileData;
        [serviceProvider requestDataFromWebService:request];
    }
 }
 
 -(NSString*)applicationVersionNumber
 {
    return @"1.0";
 }
 
 -(void)didReceivedConsoleVersion:(NSString*)consoleVersion
 {
    NSLog(@"RESULT CONSOLE VERSION : %@", consoleVersion); 
 }
 
 
 \endcode
 
 
 * \subsection subsec_2 2) Web service communication.
 In order to communicate with the LFopen server, developer needs to register LFconnect services. Next you need to authenticate with Life Fitness web service using OAuth2 protocol\n\n
 <b>Example:</b>
 \code
 LFServiceProvider *serviceProvider = [LFServiceProvider getInstance];
 [serviceProvider registerForWebService:self];
 \endcode 
 
 To communicate with the Life Fitness web services you have to extract OAuth2 token as in following example.\n\n
 <b>Example:</b>
 \code
 -(void) doAuthorization
 {
 
    LFOAuthAccessToken *token = (LFOAuthAccessToken*)[NSKeyedUnarchiver unarchiveObjectWithFile:@"YourPath/yourFileName"];
 
    LFAuthRequest *req = [[LFAuthRequest alloc] init];
    req.rootViewDelegate = self; //Just need to set delegate (should be instance of current visible view controller)
 
    if (token == nil)
    {
        [serviceProvider authorizeLFWebService:req];
    }
    else if([token hasExpired])
    {
        [serviceProvider refreshLFAccessToken:req token:token];
    }
 }
 
 #pragaram delegate method
 - (void)didReceivedLFAuthorizationToken:(LFOAuthAccessToken*)token
 {
    NSLog(@"AUTH ACCESS TOKEN : %@",token.accessToken);
    [NSKeyedArchiver archiveRootObject:token toFile:@"YourPath/yourFileName"];
 }
 \endcode
 
 To send the request to the LFconnect server, user needs to create instance of 'LFRequest' object and set appropriate parameter for it and call the function
 call "requestDataFromWebService". You'll need to send OAuth2 access token with every request. \n\n
 <b>Example:</b>
 \code
    LFOAuthAccessToken *token = (LFOAuthAccessToken*)[NSKeyedUnarchiver unarchiveObjectWithFile:@"YourPath/yourFileName"];
    LFWorkoutDetailRequest *wdr = [[LFWorkoutDetailRequest alloc] init];
    request.access_token = token.accessToken;
    wdr.lastUpdateDate = @"07/26/2008";
    wdr.equipmentId = @"4";
    wdr.requestType = LFDefaultPresetsDetailRequestType;
    [serviceProvider requestDataFromWebService:wdr];
 \endcode 
 The 'WebServiceDelegate' provides a functional interface to users wanting LFopen API to communicate with LFconnect.
 Following example describes usage example of the WebServiceDelegate. \n\n
 
  <b>Example:</b>
 \code{.cpp}
 #pragma mark WebService delegate
 -(void)didReceivedResponseWith:(LFResponse*)response
 {
    LFResponse *res = response;
    switch (res.requestType)
    {
        case LFWorkoutsListRequestType:
            if (res.responseStatus == LFSuccessfulResponse)
            {
                [self handleWorkoutSummaryResult:res.resultSet];
            }
        break;
 
        case LFWorkoutsDetailRequestType:
            if (res.responseStatus == LFSuccessfulResponse)
            {
                [self handleWorkoutDetailResult:res.resultSet];
            }
        break; 
 
        case LFAuthenticationRequestType:
            LFAuthResponse *authRes = (LFAuthResponse*)res;
            [self handleAuthResponse:authRes];
            break;
        
        default:
        break;
    }
 }
 
 #pragma Handle workout summary result
 -(void)handleWorkoutSummaryResult:(NSMutableArray*)result
 {
    if (presetList == nil )
    {
        self.presetList = [[NSMutableArray alloc] init];
        workoutDataList = [[NSMutableDictionary alloc] init];
    }
 
    [presetList removeAllObjects];
    for (LFWorkout *lfWkout in result) 
    {
        Workout *workout = [[Workout alloc] init];
        workout.workoutId = lfWkout.workoutId;
        workout.workoutName = lfWkout.workoutName;
        workout.workoutFileName = lfWkout.workoutFileName;
        workout.time = lfWkout.time;
        workout.distance = lfWkout.distance;
        workout.initialSpeed = lfWkout.initialSpeed;
        workout.equipmentName = lfWkout.equipmentName;
        [presetList addObject:workout];
    }
 
    [[NSNotificationCenter defaultCenter] postNotificationName:DidWorkoutSummaryListReceived object:nil];
 }
 
 #pragma Handle authentication response
 -(void)handleAuthResponse:(LFAuthResponse*)response
 {
    // manage authentication response
 }

 \endcode
 
 */