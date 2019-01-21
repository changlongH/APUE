## 会话管理 ##

- s 列出所有会话

- $ 重命名当前的会话

- d 断开当前的会话
- `:` 	进入命令行模式；此时可以输入支持的命令，例如kill-server可以关闭服务器

## 窗口管理 ##

- `c` 创建一个新窗口
- `,` 重命名当前窗口
- `1` 列出所有窗口
- `%` 水平分割窗口
- `"` 竖直分割窗口
- `n` 选择下一个窗口
- `p` 选择上一个窗口
- `0~9` 选择`0~9`对应的窗口

## 窗格管理 ##
- `!` 将当前面板置于新窗口；即新建一个窗口，其中仅包含当前面板

bind C-r source-file ~/.tmux.conf \; display "Refleshed Configure!"

bind-key k select-pane -U # up
bind-key j select-pane -D # down
bind-key h select-pane -L # left
bind-key l select-pane -R # right

setw -g mode-keys vi #copy-mode 将快捷键设置为vi 模式
bind -t vi-copy v begin-selection
bind -t vi-copy y copy-selection


set-window-option -g mode-mouse on # (setw其实是set-window-option的别名

setw -g mouse-resize-pane on # 开启用鼠标拖动调节pane的大小（拖动位置是pane之间的分隔线）
setw -g mouse-select-pane on # 开启用鼠标点击pane来激活该pane
setw -g mouse-select-window on # 开启用鼠标点击来切换活动window（点击位置是状态栏的窗口名称）
setw -g mode-mouse on # 开启window/pane里面的鼠标支持（也即可以用鼠标滚轮回滚显示窗口内容，此时还可以用鼠标选取文本）



set -g base-index 1 # index begin 1



setw -g monitor-activity on
set -g visual-activity on

set -wg window-status-format " #I:#w"
set -wg window-status-current-format " #I:#w#F"
set -wg window-status-separator ""
set -g status-justify centre  # centre

set-window-option -g window-status-current-bg red
