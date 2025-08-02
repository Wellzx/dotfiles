# Cria uma amostra de coleção
users = {'Hans': 'active', 'Éléonore': 'inactive', '景太郎': 'active'}

# Estratégia: iterar por uma cópia
for user, status in users.copy().items():
    if status == 'inactive':
        del users[user]

# Estratégia: criar uma nova coleção
active_users = {}
for user, status in users.items():
    if status == 'active':
        active_users[user] = status