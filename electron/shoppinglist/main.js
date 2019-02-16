const electron = require('electron');
const url = require('url');
const path = require('path');

const {app, BrowserWindow, Menu, ipcMain} = electron;

// Set ENV 
process.env.NODE_ENV = 'production';

let mainWindow;
let addWindow;

// Listen for app to be ready
app.on('ready', function(){
    // Create new window 
    mainWindow = new BrowserWindow({});
    // Load html into window 
    mainWindow.loadURL(url.format({
        pathname: path.join(__dirname, 'mainWindow.html'),
        protocol: 'file:',
        slashes: true
    }));
    // Quit app when closed
    mainWindow.on('closed', function(){
        app.quit();  //程序在关闭主窗口时退出，否则关闭主窗口时子窗口可能仍在运行
    });
    // Build menu from template 
    const mainMenu = Menu.buildFromTemplate(mainMenuTemplate);
    // Insert menu 
    Menu.setApplicationMenu(mainMenu);
});

// Handle create add window
function createAddWindow(){
    // Create new window 
    addWindow = new BrowserWindow({
        width: 300,
        height: 200,
        titile: 'Add Shopping List Item'
    });
    // Load html into window 
    addWindow.loadURL(url.format({
        pathname: path.join(__dirname, 'addWindow.html'),
        protocol: 'file:',
        slashes: true
    }));
    // Garbage collection handle
    addWindow.on('closed', function() {
        addWindow = null;  //addWindow指向的对象被删除时，将addWindow指向null
    });
}
// Catch item:add
ipcMain.on('item:add', function(e, item){  //app接收到addWindow中的数据后，将数据发送给mainwindow，关闭addwindow
    //console.log(item);  //命令行输出
    mainWindow.webContents.send('item:add', item);  
    addWindow.close();
});

// Create menu template
const mainMenuTemplate = [
    {
        label: 'File',
        submenu: [
            {
                label: 'Add Item',
                click(){ // When clicked
                    createAddWindow();  //调用函数，创建新窗口
                }
            },
            {
                label: 'Clear Items',
                click(){
                    mainWindow.webContents.send('item:clear');
                }
            },
            {
                label: 'Quit',
                accelerator: process.platform == 'darwin' ? 'Command+Q' : 'Ctrl+Q', // 快捷键，macOS和win/linux不同
                click(){ // When clicked
                    app.quit();
                }
            }
        ]
    }
];

// If macOS, add empty object to menu 
if(process.platform == 'darwin') {  
    mainMenuTemplate.unshift({});  //macOS中，在mainMenuTemplate最前面添加一个{}（空菜单），否则菜单可能不可见
}

// Add developer pod if not in production
if(process.env.NODE_ENV !== 'production')
    mainMenuTemplate.push({
        label: 'Developer Tools',
        submenu: [
            {
                label: 'Toggle DevTools',
                accelerator: process.platform == 'darwin' ? 'Command+I' : 'Ctrl+I', // 快捷键，macOS和win/linux不同
                click(item, focusedWindow){
                    focusedWindow.toggleDevTools();
                }
            }
            ,
            {
                role: 'reload'
            }
        ]
    });