# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_exec_simple_commands.sh                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 15:04:06 by tchobert          #+#    #+#              #
#    Updated: 2024/11/18 15:04:32 by tchobert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

{ echo "ls"; echo "pwd"; echo "exit"; } | ./minishell > output.txt
