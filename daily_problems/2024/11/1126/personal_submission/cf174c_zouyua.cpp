void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    a.push_back(0);
    for(int i = n + 1; i >= 1; i --) {
        a[i] -= a[i - 1];
    }
    ll z = 0, f = 0;
    vector<int> opz, opf, l, r;
    vector<array<int, 2>> op;
    for(int i = 1; i <= n + 1; i ++) {
        if(a[i] > 0) {
            z += a[i], opz.pb(i);
            for(int j = 0; j < a[i]; j ++) l.push_back(i);
        }
        else if(a[i] < 0) {
            f -= a[i], opf.pb(f);
            for(int j = 0; j < -a[i]; j ++) r.push_back(i - 1);
        }
    }
    for(int i = 0; i < l.size(); i ++) {
        op.push_back({l[i], r[i]});
    }
    cout << max(f, z) << endl;
    for(auto [x, y] : op) {
        cout << x << ' ' << y << endl;
    }
}
